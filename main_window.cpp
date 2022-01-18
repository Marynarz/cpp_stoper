#include "main_window.hpp"
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QMenuBar>

STOPER::MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    createActions();
    createMenus();
}

void STOPER::MainWindow::createActions()
{
    exit = new QAction(tr("&Quit"), this);
    exit->setShortcuts(QKeySequence::Quit);
    connect(exit, &QAction::triggered, this, &MainWindow::close_app);
}
void STOPER::MainWindow::createMenus()
{
    filemenu = menuBar()->addMenu(tr("File"));
    filemenu->addAction(exit);
}

void STOPER::MainWindow::close_app()
{
    close();
}