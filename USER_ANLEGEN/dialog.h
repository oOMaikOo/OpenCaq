#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include "CSql.h"
class CSql;
QT_BEGIN_NAMESPACE
class QGroupBox;
class QLabel;
class QLineEdit;
class QDialogButtonBox;
class QPushButton;
QT_END_NAMESPACE


class CNewUser : public QDialog
{
    Q_OBJECT

public:
    CNewUser(QWidget *parent = 0);
    void createFormGroupBox();
    void createButtonBox();
    void createCheckBox();
    ~CNewUser();
private slots:
    bool createUser();
private:
    QGroupBox *formGroupBox;
    QGridLayout *mainLayout;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPw;
    QLineEdit *lineEditIp;
    QDialogButtonBox *buttonBox;
    QPushButton *sendButton;
    QPushButton *closeButton;
    QCheckBox *insert;
    QCheckBox *del;
    QCheckBox *update;
    QCheckBox *select;
    QWidget *extension;
    bool i;
    bool d;
    bool u;
    bool s;
    CSql *sql;
};

#endif // DIALOG_H
