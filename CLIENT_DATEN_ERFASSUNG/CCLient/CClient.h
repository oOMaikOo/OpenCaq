#ifndef CCLIENT_H
#define CCLIENT_H

#define MAX 50      //Maximale Fehlerklassen in der Fehlersammelkarte

#include <QtGui>
#include "CSql.h"

class CCLient : public QDialog
{
    Q_OBJECT

public:
    CCLient(QWidget *parent = 0);
    ~CCLient();
private:
    void createClientHeader();      //Oberer auswahlbereich des Clients
    void createClientInputs();      //Eingabeberreich des Clients
    void createClientDownButtons(); //Abschlussbereich des Clients

    QVBoxLayout *mainLayout;
    QGridLayout *topLayout;
    QGridLayout *inputLayout;
    QGridLayout *finishLayout;
    QGroupBox *horizontalGroupBoxa;
    QGroupBox *horizontalGroupBoxb;
    QGroupBox *horizontalGroupBoxc;
    QLineEdit *lineEdits[MAX];
    QComboBox *box;
    QPushButton *button;
    QPushButton *pb_send;
    QStringList list;
    QStringList liste;
    QStringList qsl_name;
    QStringList qsl_data;
    QString string[MAX];
    QLabel *lable[MAX];
    QLabel *Name;
    QLabel *Personal;
    QLineEdit *li_Name;
    QLineEdit *li_Personal;
    QString *qs_line[MAX];
    QString *qs_lable[MAX];
    QDate date;
    QTime time;

    CSql *sql;
 private slots:

    void input();
    void sendenable(const QString &text);
    void send();
    void update(const QString &time, const QString &date);
};

#endif // CCLIENT_H
