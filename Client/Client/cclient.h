#ifndef CCLIENT_H
#define CCLIENT_H

#include <QDialog>

namespace Ui {
class CClient;
}

class CClient : public QDialog
{
    Q_OBJECT

public:
    explicit CClient(QWidget *parent = 0);
    ~CClient();

private:
    Ui::CClient *ui;
};

#endif // CCLIENT_H
