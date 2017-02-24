// ! \\ https for html ugly open
//  adrss tested : http://stackoverflow.com/questions/19614932/qt-cant-download-file-using-qnetworkaccessmanager?rq=1
//  http://pixanna.nl/materials/celiannas-parallax-tiles/interior-tiles/
//  https://qt.developpez.com/doc/4.7/qnetworkaccessmanager/

//save for me !!!
/*fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
"C:/Users/Franck/Documents/Qt projects/newDL_saveDir/untitled.html",tr("HTML(*.html);;Text(*.txt)"));*/

#include "dl.h"

DL::DL(QWidget *parent) :
    QWidget(parent)
{
    manager = new QNetworkAccessManager;    //l'appli peut envoyer des requêtes sur le réseau et recevoir des réponses
    setupUi(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(on_Finished(QNetworkReply*)));   //QNetworkReply
                                        //contient les données pour une requête envoyé par QNetworkAccessManager
}

void DL::on_pbu_go_clicked()
{
    //sauvegarde le fichier dans le repertoire sélectionné
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
 "C:/Users/Public/Downloads/untitled.html",tr("HTML(*.html);;Text(*.txt)"));

    file = new QFile;
    file->setFileName(fileName);

    QString myUrl = txt_url->text();
    QNetworkRequest request;    //demande à envoyer la requête par QNetworkAccessManager
    request.setUrl(QUrl(myUrl));
    reply = manager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(on_ReadyRead()));
    connect(reply, SIGNAL(finished()),this, SLOT(on_OpenTxt()));
    connect(reply,SIGNAL(finished()),this,SLOT(on_ReplyFinished()));

}

void DL::on_Finished(QNetworkReply*)//vérifie si il a une erreur lors du reply
{
    switch(reply->error())
    {
        case QNetworkReply::NoError:
        {
            qDebug("file is downloaded successfully.");
        }
        break;
        default:{
            qDebug(reply->errorString().toLatin1());
        };
    }
}

void DL::on_ReadyRead()
{
    qDebug() << "ready to read";
    file->open(QIODevice::WriteOnly);   //ouvre le fichier pour y écrit uniquement
    file->write(reply->readAll());      //écrit dans le fichier tout ce qu'il peut lire via le reply
}

void DL::on_OpenTxt()      //permet l'ouverture automatique du fichier par défaut
{
     qDebug() << "open file with default software";
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

void DL::on_ReplyFinished()     //termine le reply au fichier lorsqu'il n'écrit plus
{
    if(file->isOpen())
    {
        file->close();
        qDebug() << "reply file is closed";
        file->deleteLater();
        qDebug() << "reply file delete later";
    }
}
