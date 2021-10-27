#include "CSql.h"

CSql::CSql()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
}

bool CSql::SqlOpenConnection(const QString &databaseName,const QString &userName,const QString &password,const QString &hostName, const QString &driver)
{
        QSqlDatabase db = QSqlDatabase::addDatabase(driver);
        db.setPort(6699);
        db.setDatabaseName(databaseName);
        db.setHostName(hostName);
        if(!db.open(userName,password))
        {
            QMessageBox::critical(0, qApp->tr("Datenbank fehler"),db.lastError().text());
            return false;
        }
        //''''''''''''''''''''''TEST

return true;
}

bool CSql::SqlCreateNewFsk(const QString &Name, const QString &Maschin, const QString &Workstep, const QString &Costcenter, const QString &Tool)
{
    QSqlQuery query;

    query.exec("CREATE TABLE `"+Name+"` (id int primary key, ""Name varchar(20) , Personalnummer varchar(20), Datum date, Zeit TIME, Teile int(12))ENGINE=MyISAM DEFAULT CHARSET=utf8");

    query.exec("insert into Datas(Name,Maschinennummer,Arbeitsgang,Kostenstelle,Werkzeug) values ('"+Name+"','"+Maschin+"','"+Workstep+"','"+Costcenter+"','"+Tool+"')");

    SqlError(query);

return true;
}

bool CSql::SqlAddToTable(const QString &Name,const QString Line[0])
{
    QSqlQuery query;
    query.exec("ALTER table `"+Name+"` add `"+Line[0]+"` int(10)");

    SqlError(query);
return true;
}

bool CSql::SqlAddUser(bool &insert, bool &del, bool &update, bool &select, const QString &Name, const QString &Pw, const QString &Ip)
{
    QSqlQuery query;
    if(insert){
    query.exec("GRANT INSERT on Data.* to '"+Name+"'@'"+Ip+"'");
    query.exec("GRANT ALTER on Data.* to '"+Name+"'@'"+Ip+"'");
    }
    if(del){
    query.exec("GRANT DELETE on Data.* to '"+Name+"'@'"+Ip+"'");
    }
    if(update){
    query.exec("GRANT UPDATE on Data.* to '"+Name+"'@'"+Ip+"'");
    }
    if(select){
    query.exec("GRANT SELECT on Data.* to '"+Name+"'@'"+Ip+"'");
    }

    query.exec("set password for '"+Name+"'@'"+Ip+"' = password('"+Pw+"')");

    SqlError(query);

return true;
}

void CSql::SqlError(QSqlQuery &query)
{
    if(!query.isActive()){
        QMessageBox::critical(0, qApp->tr("Datenbank fehler"),query.lastError().text());
    }
}

void CSql::SqlCatchDataName(QStringList &list)
{
    QSqlQuery query;
    query.exec("SELECT Name FROM `Data`.Datas D");
    while (query.next()) {
        QString line = query.value(0).toString();
        list<<line;
        qDebug() << list << ":" ;
       }
    SqlError(query);
}

void CSql::SqlCatchDataMaschin(QStringList &list,const QString &Name)
{
    QSqlQuery query;
    query.exec("SELECT Maschinennummer FROM `Datas` WHERE Name = '"+Name+"'");
    while (query.next()) {
        QString line = query.value(0).toString();
        list<<line;
        qDebug() << list << ":" ;
       }
    SqlError(query);
}

CSql::~CSql()
{

}
