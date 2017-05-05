#include "qscenariotransfert.h"

QScenarioTransfert::QScenarioTransfert(QWidget *parent) :
    QDialog(parent)
{
    manager = new QNetworkAccessManager ;

    cmds = new QTcpSocket(this);
    data = new QTcpSocket(this);
    serv.listen(QHostAddress::Any,1214);
    //data->connectToHost("127.0.0.1", 22);

    connect(cmds, SIGNAL(readyRead()), this, SLOT(readCmds()));
    //connect(data, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(cmds, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(on_Finished(QNetworkReply*)));
}

void QScenarioTransfert::startListing(QPlainTextEdit& text_edit)
{
    cmds->connectToHost("127.0.0.1", 21);
    QScenarioDir* root = new QScenarioDir();
    root->setFilename("/");
    root->setFullpath("/");
    list(root,text_edit);
    cmds->write("QUIT");
    cmds->close();
    root->list(text_edit,0);
}

void QScenarioTransfert::list(QScenarioDir *directory, QPlainTextEdit& text_edit) //QPlainTextEdit& text_edit
{

    cmds->write("USER user\r\n");
    cmds->waitForBytesWritten();
    cmds->waitForReadyRead();
    cmds->write("PASS 123\r\n");
    cmds->waitForBytesWritten();
    cmds->waitForReadyRead();
    cmds->write("PORT 127,0,0,1,4,190");
    cmds->waitForBytesWritten();
    cmds->waitForReadyRead();
    QString list_request ;
    list_request += "LIST " ;
    list_request += directory->getFilefullpath();
    list_request += "\r\n";
    cmds->write(list_request.toStdString().c_str());
    cmds->waitForBytesWritten();
    cmds->waitForReadyRead();
    serv.waitForNewConnection(100000);
    data = serv.nextPendingConnection();
    qDebug() << "Reading data";
    //qDebug() << data->readAll();
    data->waitForReadyRead();
    //qDebug() << data->readAll();
    //qDebug() << "\n" ;
    QString contenu(data->readAll());
    QList<QString> liste_lignes = contenu.split("\r\n", QString::KeepEmptyParts);
    for(int i=0;i<liste_lignes.size();i++)
        //liste_lignes[i].remove(0,59) recuperation nom fichier/dossier
    {
        if(liste_lignes[i].startsWith("-")) //qscenariofile
        {
            qDebug() << " Fichier ";
            QScenarioFile *scnFile = new QScenarioFile;
            liste_lignes[i].remove(0,59);
            scnFile->setFilename(liste_lignes[i]);
            QString path = directory->getFilefullpath();
            path += liste_lignes[i];
            scnFile->setFullpath(path);
            directory->addFile(scnFile);
        }

        else if(liste_lignes[i].startsWith("d")) //qscenariodir
        {
            qDebug() << " Dossier ";
            QScenarioDir *scnDir = new QScenarioDir();
            liste_lignes[i].remove(0,59);
            scnDir->setFilename(liste_lignes[i]);
            QString path = directory->getFilefullpath();
            path += liste_lignes[i];
            path += "/";
            scnDir->setFullpath(path);
            directory->addFile(scnDir);
            list(scnDir, text_edit);
        }
    }

}

void QScenarioTransfert::get(QString fileName)
{
    QString fileGet;
    //charge le fichier dans le repertoire sélectionné sur ce pc
    file = new QFile;
    qDebug("charge le fichier à l'emplacement choisi");
    fileGet = QFileDialog::getSaveFileName(this, tr("Emplacement"),
 "C:/Users/franck/Documents/import_server_test/untitled.scn",tr("SCN(*.scn)"));

    file->setFileName(fileGet);
    qDebug("fichier créé");

    path = new QUrl("ftp://127.0.0.1/");
    path->setUserName("user");
    path->setPassword("123");

    QString myFile = fileName; //récupère le fichier choisi(grâce à son nom) sur le serveur où myFile est le nom COMPLET du fichier
    path->setPath(myFile);              // prends en compte uniquement le fichier et nom le chemin => impossible de prendre un fichier dans un autre repertoire
    qDebug("nom de fichier ajouter à path");

    QNetworkRequest request;    //demande à envoyer la requête par QNetworkAccessManager à l'adresse path
    request.setUrl(QUrl(*path));
    qDebug("requête créée et envoyée");

    reply = manager->get(request);

    connect(reply,SIGNAL(readyRead()),this,SLOT(on_ReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(on_ReplyFinished()));
}

void QScenarioTransfert::put(QString dirPath)
{
    //sauvegarde le fichier sur le serveur
    //chemin du fichier à envoyer
    QString filePath = QFileDialog::getOpenFileName(this, tr("Fichier à sauvegarder sur le serveur."),
    "C:/Users/franck/Documents/import_server_test/something.scn",tr("SCN(*.scn)"));

    QFile fileToSave(filePath); //fichier du pc
    QFileInfo fileInfo(filePath); //récupération des infos du fichier afin de pouvoir récupérer son nom
    QString selectedFileName = fileInfo.fileName(); //récupération du nom
    QFile fileUploaded;         //fichier à envoyer

    //prépare la création du fichier sur le serveur avec son nom
    QString fileUName(selectedFileName);
    fileUploaded.setFileName(fileUName);

    //addresse à upload
    QUrl uploadurl("ftp://127.0.0.1/");
    uploadurl.setUserName("user");
    uploadurl.setPassword("123");
    uploadurl.setPort(21);

    //ajoute le repertoire choisi et l'ajoute avec le fichier à l'url
    QString directory = dirPath;
    QString myPath = directory + fileUName;
    uploadurl.setPath(/*fileUName*/myPath);

    QNetworkRequest upload(uploadurl);

    //lit le fichier à sauver sur le serveur
    fileToSave.open(QIODevice::ReadOnly);
    QByteArray data;
    data = fileToSave.readAll();

    reply = manager->put(upload, data);

    //écrit pour le fichier au serveur
    fileUploaded.open(QIODevice::WriteOnly);
    fileUploaded.write(data);

}

void QScenarioTransfert::on_Finished(QNetworkReply*)
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

void QScenarioTransfert::on_ReadyRead()
{
    qDebug() << "ready to read";
    file->open(QIODevice::WriteOnly);
    file->write(reply->readAll());
}

void QScenarioTransfert::on_ReplyFinished()
{
    if(file->isOpen())
    {
        file->close();
        qDebug() << "reply file is closed";
        file->deleteLater();
        qDebug() << "reply file delete later";
    }
}

void QScenarioTransfert::readCmds()
{
    qDebug() << "Reading cmds";
    qDebug() << cmds->readAll();
    qDebug() << "\n" ;
    //qDebug() << "Reading data";
    //qDebug() << data->readAll();
}

void QScenarioTransfert::readData()
{
    data->waitForBytesWritten();
    data->waitForReadyRead();
    qDebug() << "Reading data";
    qDebug() << data->readAll();
    qDebug() << "\n" ;
    data->waitForBytesWritten();
    data->waitForReadyRead();
    qDebug() << "Reading data";
    qDebug() << data->readAll();
    qDebug() << "\n" ;
    //qDebug() << "Reading data";
    //qDebug() << data->readAll();
}

void QScenarioTransfert::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}
