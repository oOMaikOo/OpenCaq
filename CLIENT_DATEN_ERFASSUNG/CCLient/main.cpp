#include <QtGui/QApplication>
#include "CClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCLient w;
    w.show();
    return a.exec();
}
