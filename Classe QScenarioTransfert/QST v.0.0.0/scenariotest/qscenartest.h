#ifndef QSCENARTEST_H
#define QSCENARTEST_H

#include "ui_qscenartest.h"
#include "qscenariotransfert.h"

class QScenarioTransfert;

class QScenarTest : public QDialog, private Ui::QScenarTest
{
    Q_OBJECT
    QScenarioTransfert transfert ;
public:
    explicit QScenarTest(QWidget *parent = 0);
private slots:
    void on_pbu_go_clicked();
    void on_pbu_load_clicked();
    void on_pbu_list_clicked();
    void on_pbu_log_clicked();
};

#endif // QSCENARTEST_H
