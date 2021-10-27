#include "CNewFsk.h"

CNewFsk::CNewFsk(QWidget *parent) : QDialog(parent)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    createFormGroupBoxa();
    createFormGroupBoxb();
    createButtonBox();
    mainLayout = new QVBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(formGroupBoxa,0,0);
    mainLayout->addWidget(buttonBox,1,0);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(formGroupBoxb,2,0);
    setLayout(mainLayout);
    setWindowTitle(tr("Fehlersammelkate anlegen"));

    sql->SqlOpenConnection("Data","root");
}

void CNewFsk::createFormGroupBoxa()
{
    formGroupBoxa = new QGroupBox(tr("Kopfdaten fuer Fehlersammelkarte"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Name :")), lineEditName = new QLineEdit);
    layout->addRow(new QLabel(tr("Maschinennr. :")),lineEditMaschin = new QLineEdit);
    layout->addRow(new QLabel(tr("Arbeitsgang :")), lineEditWorkstep = new QLineEdit);
    layout->addRow(new QLabel(tr("Kostenstelle :")), lineEditCostcenter = new QLineEdit);
    layout->addRow(new QLabel(tr("Werkzeug :")), lineEditTool = new QLineEdit);
    layout->addRow(new QLabel(tr("Fehlerklassen :")), spinbox = new QSpinBox);

    spinbox->setMaximum(MAX);
    formGroupBoxa->setMaximumWidth(500);
    formGroupBoxa->setMinimumWidth(500);

    spinbox->setValue(0);

    connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(changeLine(int)));

    formGroupBoxa->setLayout(layout);


}

void CNewFsk::createFormGroupBoxb()
{
    formGroupBoxb = new QGroupBox(tr("Fehlerklasse der Fehlersammelkarte"));
    QFormLayout *layout = new QFormLayout;
    formGroupBoxb->setMaximumWidth(500);
    formGroupBoxb->setMinimumWidth(500);
    formGroupBoxb->setLayout(layout);
}

void CNewFsk::changeLine(int i)
{
    int index = mainLayout->indexOf(formGroupBoxb);
    mainLayout->removeWidget(formGroupBoxb);
    delete formGroupBoxb;
    formGroupBoxb = new QGroupBox(tr("Fehlerklassen der Fehlersammelkarte"));
    QFormLayout *layout = new QFormLayout;
        for (int a = 0; a < i; ++a) {
      layout->addRow(labels[a] = new QLabel(tr("Fehlerklasse %1:").arg(a + 1)),
                   lineEdits[a] = new QLineEdit);
     }
    formGroupBoxb->setMaximumWidth(500);
    formGroupBoxb->setMinimumWidth(500);
    formGroupBoxb->setLayout(layout);
    mainLayout->insertWidget( index, formGroupBoxb,1,0);
}

void CNewFsk::createButtonBox()
{
    buttonBox = new QDialogButtonBox;
    sendButton = buttonBox->addButton(tr("Speichern"),QDialogButtonBox::ActionRole);
    closeButton = buttonBox->addButton(tr("Abrechen"),QDialogButtonBox::ActionRole);

    connect(sendButton, SIGNAL(clicked()), this, SLOT(CreateFsk()));
}

void CNewFsk::CreateFsk()
{
    sql->SqlCreateNewFsk(lineEditName->text(),lineEditMaschin->text(),lineEditWorkstep->text(),lineEditCostcenter->text(),lineEditTool->text());

    int i = spinbox->value();
    for (int a = 0; a < i; ++a) {
        inputs[a] = new QString;
        *inputs[a] = lineEdits[a]->text();
        sql->SqlAddToTable(lineEditName->text(),lineEditWorkstep->text(),inputs[a]);
    }

}
CNewFsk::~CNewFsk()
{
    SAFE_DELETE(mainLayout);
    SAFE_DELETE(lineEditName);
    SAFE_DELETE(lineEditMaschin);
    SAFE_DELETE(lineEditWorkstep);
    SAFE_DELETE(lineEditCostcenter);
    SAFE_DELETE(lineEditTool);
    SAFE_DELETE(spinbox);
    SAFE_DELETE(formGroupBoxa);
    SAFE_DELETE(formGroupBoxb);
    SAFE_DELETE(buttonBox);
}
