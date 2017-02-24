/*
 * Program name : newDL
 * Author : ME FRONCKY
 * Date : 24/feb/2017
 * Version : v1.0
 * Watzat : Permet de télécharger et sauver le code source d'une page
 * web au format txt ou html et de s'ouvrir automatiquement avec son
 * logiciel par défaut.
 */

#pragma once

#include "ui_dl.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QDesktopServices>

class DL : public QWidget, private Ui::DL
{
    Q_OBJECT

public:
    explicit DL(QWidget *parent = 0);
private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
    QString fileName;

private slots:
    void on_pbu_go_clicked();
    void on_Finished(QNetworkReply*);
    void on_ReadyRead();
    void on_OpenTxt();
    void on_ReplyFinished();
};
