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
            qDebug("Verbindung zur Datenbank konnte nicht hergestellt werden.");
        }
return true;
}

bool CSql::SqlCreateNewFsk(const QString &Name, const QString &Maschin, const QString &Workstep, const QString &Costcenter, const QString &Tool)
{
    QSqlQuery query;

    query.exec("CREATE TABLE `"+Name+"` (id int primary key, ""Name varchar(20) , Personalnummer varchar(20), Datum date, Zeit TIME, Teile int(12))ENGINE=MyISAM DEFAULT CHARSET=utf8");

    query.exec("insert into Datas(Name,Maschinennummer,Arbeitsgang,Kostenstelle,Werkzeug) values ('"+Name+"','"+Maschin+"','"+Workstep+"','"+Costcenter+"','"+Tool+"')");

return true;
}

bool CSql::SqlAddToTable(const QString &Name,const QString Line[0])
{
    QSqlQuery query;
    query.exec("ALTER table `"+Name+"` add `"+Line[0]+"` int(10)");

return true;
}

bool CSql::SqlAddUser(const QString &Name, const QString &Pw, const QString &Ip)
{
    QSqlQuery query;
    query.exec("GRANT CREATE,INSERT,DELETE,UPDATE,SELECT on Data.* to '"+Name+"'@'"+Ip+"'");
    query.exec("set password for '"+Name+"'@'"+Ip+"' = password('"+Pw+"')");
return true;
}

CSql::~CSql()
{

}
