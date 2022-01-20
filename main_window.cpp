#include "main_window.hpp"

STOPER::MainWindow::MainWindow()
{
    LOGF("Enter MainWindow constructor");
    widget = new QWidget;
    setCentralWidget(widget);
    createLayout();
    widget->setLayout(layout);
    widget->show();

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

void STOPER::MainWindow::createLayout()
{
    layout = new QGridLayout(widget);
    label1 = new QLabel("Dupa123;");
    layout->addWidget(label1, 0, 0);
}

void STOPER::MainWindow::close_app()
{
    close();
}