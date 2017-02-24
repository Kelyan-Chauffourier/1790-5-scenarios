#include "dl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DL w;
    w.show();

    return a.exec();
}
