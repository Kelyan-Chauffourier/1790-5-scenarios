#include "qscenartest.h"
#include "qscenariotransfert.h"

QScenarTest::QScenarTest(QWidget *parent) :
    QDialog(parent),
    transfert(this)
{
    setupUi(this);
}

void QScenarTest::on_pbu_go_clicked()
{
    QString fileName = edt_file->text();
    transfert.get(fileName);
}


void QScenarTest::on_pbu_load_clicked()
{
    QString dirPath = edt_file->text();
    transfert.put(dirPath);
}

void QScenarTest::on_pbu_list_clicked()
{

    transfert.startListing(*text_edit);

}

void QScenarTest::on_pbu_log_clicked()
{
    /*QString adresse = edt_lAdrss->text();
    QString id = edt_nom->text();
    QString pass = edt_pass->text();
    transfert.login(&id,&pass,&adresse,21);*/

}
