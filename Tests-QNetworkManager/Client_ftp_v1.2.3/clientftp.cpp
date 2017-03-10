//qDebug("");
#include "clientftp.h"

Clientftp::Clientftp(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    pbu_load->setEnabled(false);
    pbu_save->setEnabled(false);

    //l'appli peut maintenant envoyer des requêtes sur le réseau
    manager = new QNetworkAccessManager();

    //adresse : path + id + password destiné à l'url de requête
    path = new QUrl("ftp://127.0.0.1/");
    path->setUserName("Quentin");
    path->setPassword("123");

    lister();

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(on_Finished(QNetworkReply*)));
}

void Clientftp::lister()
{
    //sauvegarde un fichier temporaire pour permettre de renvoyer la liste du répertoire
    file = new QFile;
    file->setFileName("C:/Users/Franck/Documents/import_server_test/liste.txt");
    qDebug("fichier temporaire créé");

    QNetworkRequest request;
    path->setPath("liste.txt");
    request.setUrl(QUrl(*path));
    qDebug("requête créée et envoyée");

    reply = manager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(on_ReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(on_ReplyFinished()));
    connect(reply,SIGNAL(finished()),this,SLOT(start_Listing()));
}

//ouvre le fichier et place le texte de la liste sur le fichier
void Clientftp::start_Listing()
{
    qDebug() << "open file and make the list";
    if ( !file->open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    QTextStream in(file) ;
    list->setText(in.readAll());
    file->close();
}

void Clientftp::on_rbu_editor_clicked()
{
    pbu_load->setEnabled(true);
    pbu_save->setEnabled(true);
}

void Clientftp::on_rbu_player_clicked()
{
    pbu_load->setEnabled(true);
    pbu_save->setEnabled(false);
}

void Clientftp::on_pbu_load_clicked()
{
    file = new QFile;
    //sauvegarde le fichier dans le repertoire sélectionné
    qDebug("charge le fichier à l'emplacement choisi");
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
 "C:/Users/franck/Documents/import_server_test/untitled.scn",tr("SCN(*.scn)"));


    file->setFileName(fileName);
    qDebug("fichier créé");

    //A VIRER UNE FOIS LA LISTE FONCTIONNELLE par le clique !!!!!!!!!!!!!!!!!!!!!
    QString myFile = edt_file->text(); //récupère le fichier choisi(grâce à son nom) sur le serveur où myFile est le nom COMPLET du fichier
    path->setPath(myFile);
    qDebug("nom de fichier ajouter à path");

    QNetworkRequest request;    //demande à envoyer la requête par QNetworkAccessManager à l'adresse path
    request.setUrl(QUrl(*path));
    qDebug("requête créée et envoyée");

    reply = manager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(on_ReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(on_ReplyFinished()));
}

void Clientftp::on_pbu_save_clicked()
{

}

void Clientftp::on_Finished(QNetworkReply*)
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

void Clientftp::on_ReadyRead()
{
    qDebug() << "ready to read";
    file->open(QIODevice::WriteOnly);
    file->write(reply->readAll());
}

void Clientftp::on_ReplyFinished()
{
    if(file->isOpen())
    {
        file->close();
        qDebug() << "reply file is closed";
        file->deleteLater();
        qDebug() << "reply file delete later";
    }
}
