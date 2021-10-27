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
#include "CSql.h"

CSql::CSql()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
}
////####
////Modul   :   Allgemein
////Verbindung zur Datenbank aufbauen////
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
return true;
}
////####
////Modul   :   Neue Fehlersammelkarte anlegen (NewFsk)
////Neue Fehlersammelkarte in der Datenbank erstellen////
bool CSql::SqlCreateNewFsk(const QString &Name, const QString &Maschin, const QString &Workstep, const QString &Costcenter, const QString &Tool)
{
    QSqlQuery query;

    query.exec("CREATE TABLE `"+Name+" "+Workstep+"` (""Name varchar(20) , Personalnummer varchar(20), Datum date, Zeit TIME, Teile int(12))ENGINE=MyISAM DEFAULT CHARSET=utf8");

    query.exec("insert into Datas(Name,Maschinennummer,Arbeitsgang,Kostenstelle,Werkzeug) values ('"+Name+" "+Workstep+"','"+Maschin+"','"+Workstep+"','"+Costcenter+"','"+Tool+"')");

    SqlError(query);

return true;
}
////####
////Modul   :   Neue Fehlersammelkarte anlegen (NewFsk)
////Fehlerklassen zur Fehlersammelkarte hinzufügen////
bool CSql::SqlAddToTable(const QString &Name,const QString &Workstep, const QString Line[0])
{
    QSqlQuery query;
    query.exec("ALTER table `"+Name+" "+Workstep+"` add `"+Line[0]+"` int(10)");

    SqlError(query);
return true;
}
////####
////Modul   :   Benutzerverwaltung
////Benutzer für die Datenbank anlegen////
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
////####
////Modul   :   SQL intern
////SQL Fehlerhandling////
void CSql::SqlError(QSqlQuery &query)
{
    if(!query.isActive()){
        QMessageBox::critical(0, qApp->tr("Datenbank fehler"),query.lastError().text());
    }
}
////####
////Modul   :   eFSK Client
////eFSK Client holt sich die Aktuellen Vorhandenen eFSK aus der Datenbank////
void CSql::SqlCatchFskName(QStringList &list)
{
    QSqlQuery query;
    QString line;
    query.exec("SELECT `Name` FROM Datas");
    while (query.next()) {
        line = query.value(0).toString();
        list.append(line);
       }
    SqlError(query);
}
////####
////Modul   :   eFSK Client
////eFSK Client holt sich die Fehlereinträge aus der Datenbank zur entsprechenden eFSK////
void CSql::SqlCreateFskInput(const QString &Name, QStringList &list)
{
    QSqlQuery query;
    QString line;
    query.exec("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '"+Name+"'");
    while (query.next()) {
        line = query.value(0).toString();
        list.append(line);
    }
    SqlError(query);
}
////####
////Modul   :   eFSK Client
////eFSK Client sendet die eingegebenen Daten vom eFSK Client an die Datenbank////
void CSql::SqlSendData(const QString &Fsk, const QString &Name, const QString &Personal,const QString &date,QString &time)
{
    QSqlQuery query;
    query.exec("INSERT INTO `"+Fsk+"`(Name,Personalnummer,Datum,Zeit) VALUES ('"+Name+"','"+Personal+"','"+date+"','"+time+"')");
    SqlError(query);
}
////####
////Modul   :   eFSK Client
////eFSK Client sendet die eingegebenen Daten an die Datenbank(Fehlereingabe)////
void CSql::SqlUpdateData(const QString &Fsk, const QString &Name, const QString &Personal,const QString &date,const QString &time, const QString lable[0], const QString text[0])
{
    QSqlQuery query;
    query.exec("UPDATE `"+Fsk+"` SET `"+lable[0]+"` = '"+text[0]+"' WHERE Datum = '"+date+"' AND Zeit = '"+time+"' AND Name = '"+Name+"' AND Personalnummer = '"+Personal+"'");
    SqlError(query);
}


CSql::~CSql()
{

}
