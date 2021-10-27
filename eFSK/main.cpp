#include <QApplication>

#include "CNewFsk.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CNewFsk Fsk;

    Fsk.show();

    return a.exec();
}
