#pragma once

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QDesktopServices>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

#include "ui_clientftp.h"


class Clientftp : public QDialog, private Ui::Clientftp
{
    Q_OBJECT

public:
    explicit Clientftp(QWidget *parent = 0);
    void lister();

private slots:
    void on_rbu_editor_clicked();
    void on_rbu_player_clicked();
    void on_pbu_load_clicked();
    void on_pbu_save_clicked();

    void on_Finished(QNetworkReply*);
    void on_ReadyRead();
    void start_Listing();
    void on_ReplyFinished();

private:
    QNetworkAccessManager   *manager;
    QNetworkRequest         *request;
    QNetworkReply           *reply;
    QFile                   *file;
    QUrl                    *path;
    QString                 fileName;
};
