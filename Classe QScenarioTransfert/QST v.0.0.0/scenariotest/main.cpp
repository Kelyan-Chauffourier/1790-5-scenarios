#include "qscenartest.h"
#include "qscenariotransfert.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScenarTest w;
    w.show();

    return a.exec();
}
