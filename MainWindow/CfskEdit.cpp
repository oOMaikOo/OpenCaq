#include <QtGui>
#include "CfskEdit.h"

CFskEdit::CFskEdit(QWidget *parent) : QDialog(parent)
{
    label = new QLabel(tr("Finden &what:"));
    line = new QLineEdit;
    label->setBuddy(line);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect(line, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));
    connect(findButton, SIGNAL(clicked()),this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *topleftLayout = new QHBoxLayout;
    topleftLayout->addWidget(label);
    topleftLayout->addWidget(line);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topleftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
    setFixedWidth(sizeHint().width());

}

void CFskEdit::CreateFsk()
{


}

void CFskEdit::findClicked()
{
    QString text = line->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    if(backwardCheckBox->isChecked()){
        emit findPrev(text, cs);
    }else{
        emit findNext(text, cs);
    }
}

void CFskEdit::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
