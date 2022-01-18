#include "main_window.hpp"
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QMenuBar>

STOPER::MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    setFixedSize(100, 50);

    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);
    exit = new QAction(tr("&Quit"), this);
    exit->setShortcuts(QKeySequence::Quit);
    connect(exit, &QAction::triggered, this, &MainWindow::close_app);

    filemenu = menuBar()->addMenu(tr("File"));
    filemenu->addAction(exit);
}

void STOPER::MainWindow::close_app()
{
    close();
}