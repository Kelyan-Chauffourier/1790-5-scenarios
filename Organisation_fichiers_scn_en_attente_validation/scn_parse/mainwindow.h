#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "event.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void parse(const QString& filePath) ;
private:
    QList<Object> objects ;
    QList<Event> events ;
private slots:
    void on_pbuFileSelect_clicked();
};

#endif // MAINWINDOW_H
