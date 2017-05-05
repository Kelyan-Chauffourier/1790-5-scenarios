#ifndef QFTP_H
#define QFTP_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QFileDialog>
#include <QTcpSocket>
#include <QTcpServer>

#include <qplaintextedit.h>
#include "qscenariodir.h"

class QScenarioTransfert : public QDialog
{
    Q_OBJECT

public:
    explicit QScenarioTransfert(QWidget *parent = 0);

    //void login(QString user, QString pass);
    //void logout();
    void list(QScenarioDir *directory, QPlainTextEdit &text_edit);
    void get(QString fileName);
    void put(QString dirPath);

    //void cd();

    void startListing(QPlainTextEdit &text_edit);

private slots :
    void on_Finished(QNetworkReply*);
    void on_ReadyRead();
    void on_ReplyFinished();
    void readCmds();
    void readData();
    void bytesWritten(qint64 bytes);
    //void acceptConnection();

private:
     QTcpServer              serv ;
     QNetworkAccessManager  *manager;
     QNetworkRequest        *request;
     QNetworkReply          *reply;
     QUrl                   *path;
     QFile                  *file;
     QTcpSocket             *cmds, *data;


};

#endif // QFTP_H
