#include <QtGui/QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CNewUser w;
    w.show();
    return a.exec();
}
