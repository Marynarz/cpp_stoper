#include "main_window.hpp"

STOPER::MainWindow::MainWindow()
{
    LOGF("Enter MainWindow constructor");
    widget = new QWidget;
    start_time = std::chrono::steady_clock::now();
    now_time = std::chrono::steady_clock::now();
    setCentralWidget(widget);
    createLayout();
    widget->setLayout(layout);
    widget->show();

    createActions();
    createMenus();
    is_started = false;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update_time_lbl);
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
    act_time = new QLabel(QString::fromStdString(STOPER::UTILS::time_to_show(start_time, now_time)));
    start_stop_btn = new QPushButton("Start time");
    connect(start_stop_btn, &QPushButton::released, this, &MainWindow::start_stop_slot);

    layout->addWidget(act_time, 0, 0);
    layout->addWidget(start_stop_btn, 0, 1);
}

void STOPER::MainWindow::close_app()
{
    close();
}

void STOPER::MainWindow::start_stop_slot()
{
    if (!is_started)
    {
        timer->start(100);
        is_started = true;
        start_stop_btn->setText("Stop");
        start_time = std::chrono::steady_clock::now();
        now_time = std::chrono::steady_clock::now();
        LOGF("Pushed ");
    }
    else
    {
        timer->stop();
        is_started = false;
        start_stop_btn->setText("Start");
    }
}

void STOPER::MainWindow::update_time_lbl()
{
    now_time = std::chrono::steady_clock::now();
    act_time->setText(QString::fromStdString(STOPER::UTILS::time_to_show(start_time, now_time)));
}