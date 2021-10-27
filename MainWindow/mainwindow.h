#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CFskEdit;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void Fsk();
    CFskEdit *createMdiChild();
    void setActiveSubWindow(QWidget *window);

private:
    void createAction();
    void createMenu();
    void readSettings();
    void writeSettings();

    QMdiArea *mdiArea;
    QSignalMapper *windowMapper;
    QMenu *CaqMenuModul;
    QMenu *eFsk;
    QAction *newFsk;
    QAction *Quit;
    QAction *edit;
};

#endif // MAINWINDOW_H
