#include "CClient.h"

CCLient::CCLient(QWidget *parent)
    : QDialog(parent)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    sql->SqlOpenConnection("Data","root");

    createClientHeader();
    createClientInputs();
    createClientDownButtons();
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(horizontalGroupBoxa,0,0);
    mainLayout->addWidget(horizontalGroupBoxb,1,0);
    mainLayout->addWidget(horizontalGroupBoxc,2,0);
    setLayout(mainLayout);
    setWindowTitle(tr("Client zur eFSK erfassung"));
}

void CCLient::createClientHeader()
{
    horizontalGroupBoxa = new QGroupBox(tr("Fehlersammelkarte auswahl"));
    topLayout = new QGridLayout;
    box = new QComboBox;
    button= new QPushButton(tr("Ok"));
    box->setFixedWidth(350);
    button->setFixedWidth(100);
    button->setFixedHeight(30);
    topLayout->addWidget(box,0,0);
    topLayout->addWidget(button,0,1);

    sql->SqlCatchFskName(list);

    box->addItems(list);

    connect(button, SIGNAL(clicked()), this, SLOT(input()));

    horizontalGroupBoxa->setLayout(topLayout);
}
void CCLient::createClientInputs()
{
    horizontalGroupBoxb = new QGroupBox(tr("Dateneingabe"));
    inputLayout = new QGridLayout;
    horizontalGroupBoxb->setLayout(inputLayout);
}

void CCLient::input()
{
    liste.clear();

    int index = mainLayout->indexOf(horizontalGroupBoxb);
    mainLayout->removeWidget(horizontalGroupBoxb);
    delete horizontalGroupBoxb;

    horizontalGroupBoxb = new QGroupBox(tr("Dateneingabe"));
    inputLayout = new QGridLayout;

    sql->SqlCreateFskInput(box->currentText(),liste);
    for (int i = 4; i < liste.size(); i++){
        string[i] = liste.at(i);
        lable[i] = new QLabel(string[i]);

        lineEdits[i] = new QLineEdit;

        inputLayout->addWidget(lable[i],i,0);
        inputLayout->addWidget(lineEdits[i],i,1);
        lineEdits[i]->setFixedWidth(100);
    }
    horizontalGroupBoxb->setLayout(inputLayout);
    mainLayout->insertWidget(index,horizontalGroupBoxb,1,0);
}

void CCLient::createClientDownButtons()
{
    horizontalGroupBoxc = new QGroupBox(tr("Daten senden"));
    finishLayout = new QGridLayout;
    Name = new QLabel(tr("Name :"));
    Personal = new QLabel(tr("Personalnummer :"));
    finishLayout->addWidget(Name,0,0);
    finishLayout->addWidget(Personal,1,0);
    li_Name = new QLineEdit;
    li_Personal = new QLineEdit;
    li_Name->setFixedWidth(200);
    li_Personal->setFixedWidth(100);
    finishLayout->addWidget(li_Name,0,1);
    finishLayout->addWidget(li_Personal,1,1);
    pb_send = new QPushButton(tr("Speichern"));
    pb_send->setFixedHeight(30);
    pb_send->setEnabled(false);
    finishLayout->addWidget(pb_send,2,1);
    connect(li_Personal, SIGNAL(textChanged(const QString &)), this, SLOT(sendenable(const QString &)));
    connect(pb_send, SIGNAL(clicked()), this, SLOT(send()));
    horizontalGroupBoxc->setLayout(finishLayout);
}

void CCLient::sendenable(const QString &text)
{
    pb_send->setEnabled(!text.isEmpty());
}

void CCLient::send()
{
    time = QTime::currentTime();
    date = QDate::currentDate();
    QString qs_time = time.toString("hh:mm:ss");
    QString qs_date = date.toString("yyyy.MM.dd");

    sql->SqlSendData(box->currentText(), li_Name->text(), li_Personal->text(),qs_date,qs_time);
    update(qs_time,qs_date);
}

void CCLient::update(const QString &time, const QString &date)
{
    for (int i = 4; i < liste.size(); i++){
        qs_line[i] = new QString;
        qs_lable[i] = new QString;
        *qs_lable[i] = lable[i]->text();
        *qs_line[i] = lineEdits[i]->text();

        sql->SqlUpdateData(box->currentText(), li_Name->text(), li_Personal->text(),date,time,qs_lable[i],qs_line[i]);
    }
}
CCLient::~CCLient()
{

}
