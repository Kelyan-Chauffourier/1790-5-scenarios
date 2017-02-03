#include "cclient.h"
#include "ui_cclient.h"

CClient::CClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CClient)
{
    ui->setupUi(this);
}

CClient::~CClient()
{
    delete ui;
}
