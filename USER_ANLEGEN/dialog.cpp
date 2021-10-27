#include "dialog.h"

CNewUser::CNewUser(QWidget *parent)
    : QDialog(parent)
{
    sql->SqlOpenConnection("Data");
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    createFormGroupBox();
    createButtonBox();
    createCheckBox();
    mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(formGroupBox,0,0);
    mainLayout->addWidget(buttonBox,1,1);
    mainLayout->addWidget(extension,0,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Benutzer anlegen"));

    formGroupBox->setMaximumWidth(350);
    formGroupBox->setMinimumWidth(350);

}

void CNewUser::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Neuen Benutzer anlegen"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Name :")), lineEditName = new QLineEdit);
    layout->addRow(new QLabel(tr("Passwort. :")),lineEditPw = new QLineEdit);
    layout->addRow(new QLabel(tr("Feste IP Adresse :")), lineEditIp = new QLineEdit);

    formGroupBox->setLayout(layout);
}

void CNewUser::createButtonBox()
{
    buttonBox = new QDialogButtonBox();
    sendButton = buttonBox->addButton(tr("Anlegen"),QDialogButtonBox::ActionRole);
    closeButton = buttonBox->addButton(tr("Abrechen"),QDialogButtonBox::ActionRole);

    connect(sendButton, SIGNAL(clicked()), this, SLOT(createUser()));
}

void CNewUser::createCheckBox()
{
    extension = new QWidget;
    QVBoxLayout *extensionLayout = new QVBoxLayout;
    insert = new QCheckBox(tr("Daten einfuegen"));
    del = new QCheckBox(tr("Daten loeschen"));
    update = new QCheckBox(tr("Daten updaten"));
    select = new QCheckBox(tr("Daten abrufen"));
    extensionLayout->addWidget(insert);
    extensionLayout->addWidget(del);
    extensionLayout->addWidget(update);
    extensionLayout->addWidget(select);
    extension->setLayout(extensionLayout);
}

bool CNewUser::createUser()
{
    i = insert->isChecked();
    d = del->isChecked();
    u = update->isChecked();
    s = select->isChecked();

    sql->SqlAddUser(i,d,u,s,lineEditName->text(),lineEditPw->text(),lineEditIp->text());
 return true;
}

CNewUser::~CNewUser()
{

}
