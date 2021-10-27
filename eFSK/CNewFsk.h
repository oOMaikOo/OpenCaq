#ifndef CNEWFSK_H_INCLUDED
#define CNEWFSK_H_INCLUDED

#include "CSql.h"

#define MAX 200

class CSql;

class CNewFsk : public QDialog
{
    Q_OBJECT

public:
    CNewFsk(QWidget *parent = 0);
    ~CNewFsk();
private slots:
    void changeLine(int i);
    void CreateFsk();
private:
    void createFormGroupBoxa();
    void createFormGroupBoxb();
    void createButtonBox();
    
    QGroupBox *formGroupBoxa;
    QGroupBox *formGroupBoxb;
    QVBoxLayout *mainLayout;
    QLineEdit *lineEditName;
    QLineEdit *lineEditMaschin;
    QLineEdit *lineEditWorkstep;
    QLineEdit *lineEditCostcenter;
    QLineEdit *lineEditTool;
    QSpinBox *spinbox;
    QLabel *labels[MAX];
    QLineEdit *lineEdits[MAX];
    QString *inputs[MAX];
    QDialogButtonBox *buttonBox;
    QPushButton *sendButton;
    QPushButton *closeButton;
    CSql *sql;
};
#endif // CNEWFSK_H_INCLUDED
