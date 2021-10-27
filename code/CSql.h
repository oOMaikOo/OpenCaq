//############################################################################//
//## Projekt Informationen                                                  ##//
//############################################################################//
//## Projekt Name   :   OpenCaq                                             ##//
//############################################################################//
//## Modul Name     :   SQL                                                 ##//
//## Datum          :   01.04.2010                                          ##//
//## Author         :   M.Löhn                                              ##//
//## Beschreibung   :   Datenbank verbindung und SQL Querys                 ##//
//############################################################################//
//## Modifizierungen                                                        ##//
//############################################################################//
//## Datum          :   01.05.2010                                          ##//
//## Author         :   M.Löhn                                              ##//
//## Version        :   0.0.1                                               ##//
//############################################################################//
#ifndef CSQL_H
#define CSQL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTextCodec>
#include <QDialog>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>
#include "/usr/include/qt4/Qt/qsqldatabase.h"

#define MAX 50
#define SAFE_DELETE(X) {if (X != NULL) {delete (X),X = NULL;}}

QT_BEGIN_NAMESPACE
class QGroupBox;
class QLabel;
class QLineEdit;
class QDialogButtonBox;
class QPushButton;
class QSqlError;
QT_END_NAMESPACE

class CSql  :   public QSqlDatabase
{

    public :
            CSql();
            ~CSql();
            bool SqlOpenConnection(const QString &databaseName,const QString &userName="root",const QString &password="036777",const QString &hostName="localhost", const QString &driver="QMYSQL");
            bool SqlCreateNewFsk(const QString &Name, const QString &Maschin="123",const QString &Workstep="test",const QString &Costcenter="123",const QString &Tool="123");
            bool SqlAddToTable(const QString &Name,const QString &Workstep, const QString Line[0]);
            bool SqlAddUser(bool &insert, bool &del, bool &update, bool &select, const QString &Name, const QString &Pw, const QString &Ip="%");
            void SqlError(QSqlQuery &query);
            void SqlCatchFskName(QStringList &list);
            void SqlCreateFskInput(const QString &Name, QStringList &list);
            void SqlSendData(const QString &Fsk, const QString &Name, const QString &Personal,const QString &date,QString &time);
            void SqlUpdateData(const QString &Fsk, const QString &Name, const QString &Personal,const QString &date,const QString &time, const QString lable[0], const QString text[0]);
    private :
};

#endif // CSQL_H
