#include <QtGui>
#include "mainwindow.h"
#include "CfskEdit.h"

MainWindow::MainWindow()
{
    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);
    /*connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow *)),
            this, SLOT(updateMenus()));*/
    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget *)),
            this, SLOT(setActiveSubWindow(QWidget *)));

    createAction();
    createMenu();
    readSettings();
    setWindowTitle(tr("OpenCaq"));
}

MainWindow::~MainWindow()
{

}

CFskEdit *MainWindow::createMdiChild()
{
    CFskEdit *child = new CFskEdit;
    mdiArea->addSubWindow(child);

    /*connect(child, SIGNAL(copyAvailable(bool)),
            cutAct, SLOT(setEnabled(bool)));
    connect(child, SIGNAL(copyAvailable(bool)),
            copyAct, SLOT(setEnabled(bool)));*/

    return child;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
}

void MainWindow::createAction()
{
    newFsk = new QAction(tr("&Neu"), this);
    newFsk->setShortcut(QKeySequence::New);
    newFsk->setStatusTip(tr("Neue Fehlersammelkarte anlegen"));
    connect(newFsk, SIGNAL(triggered()), this, SLOT(Fsk()));

    Quit = new QAction(tr("B&eenden"),this);
    Quit->setShortcut(tr("Ctrl+E"));
    Quit->setStatusTip(tr("Programm beenden"));
    connect(Quit, SIGNAL(triggered()), this, SLOT(close()));

    edit = new QAction(tr("&Bearbeiten"), this);
    edit->setShortcut(tr("Ctrl+B"));
    edit->setStatusTip(tr("FSK bearbeiten"));
}

void MainWindow::createMenu()
{
    CaqMenuModul = menuBar()->addMenu(tr("&Modul"));
    eFsk = CaqMenuModul->addMenu(tr("e&FSK"));
    eFsk->addAction(newFsk);
    eFsk->addAction(edit);

    CaqMenuModul->addSeparator();

    CaqMenuModul->addAction(Quit);

}

void MainWindow::readSettings()
{
    QSettings settings("TEST","OpenCaq");
    QPoint pos = settings.value("pos", QPoint(100, 100)).toPoint();
    QSize size = settings.value("size", QSize(1024, 768)).toSize();
    resize(size);
    move(pos);
}

void MainWindow::writeSettings()
{
    QSettings settings("TEST","OpenCaq");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void MainWindow::Fsk()
{
    CFskEdit *child = createMdiChild();
    child->show();
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window)
        return;
    mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}
