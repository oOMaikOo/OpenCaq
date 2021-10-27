#ifndef CSQL_H
#define CSQL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTextCodec>
#include <QDialog>
#include <QtGui>
#include "/usr/include/qt4/Qt/qsqldatabase.h"

#define SAFE_DELETE(X) {if (X != NULL) {delete (X),X = NULL;}}

QT_BEGIN_NAMESPACE
class QGroupBox;
class QLabel;
class QLineEdit;
class QDialogButtonBox;
class QPushButton;
QT_END_NAMESPACE

class CSql  :   public QSqlDatabase
{

    public :
            CSql();
            ~CSql();
            bool SqlOpenConnection(const QString &databaseName,const QString &userName="root",const QString &password="036777",const QString &hostName="localhost", const QString &driver="QMYSQL");
            bool SqlCreateNewFsk(const QString &Name, const QString &Maschin="123",const QString &Workstep="test",const QString &Costcenter="123",const QString &Tool="123");
            bool SqlAddToTable(const QString &Name,const QString Line[0]);
            bool SqlAddUser(const QString &Name, const QString &Pw, const QString &Ip="%");
    private :
};

#endif // CSQL_H
