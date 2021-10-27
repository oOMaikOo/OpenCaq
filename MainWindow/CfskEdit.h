#ifndef CFSKEDIT_H
#define CFSKEDIT_H

#include <QDialog>

class QLineEdit;
class QLabel;
class QCheckBox;
class QPushButton;

class CFskEdit  :   public QDialog
{
    Q_OBJECT

 public:
            CFskEdit(QWidget *paretn = 0);
            void CreateFsk();
 signals:
            void findNext(const QString &str, Qt::CaseSensitivity cs);
            void findPrev(const QString &str, Qt::CaseSensitivity cs);
private slots:
            void findClicked();
            void enableFindButton(const QString &text);
 private:
            QLineEdit *line;
            QLabel *label;
            QCheckBox *caseCheckBox;
            QCheckBox *backwardCheckBox;
            QPushButton *findButton;
            QPushButton *closeButton;
};




#endif // CFSKEDIT_H
