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
    act_time = new QLabel();
    show_time();

    start_stop_btn = new QPushButton("Start time");
    connect(start_stop_btn, &QPushButton::released, this, &MainWindow::start_stop_slot);

    reset_btn = new QPushButton("Reset");
    connect(reset_btn, &QPushButton::released, this, &MainWindow::reset_slot);

    layout->addWidget(act_time, 0, 0);
    layout->addWidget(start_stop_btn, 0, 1);
    layout->addWidget(reset_btn, 1, 1);
}

void STOPER::MainWindow::close_app()
{
    close();
}

void STOPER::MainWindow::start_stop_slot()
{
    if (!timer->isActive())
    {
        start_time = std::chrono::steady_clock::now();
        now_time = std::chrono::steady_clock::now();
        timer->start(100);
        start_stop_btn->setText("Stop");
        LOGF("Pushed ");
    }
    else
    {
        timer->stop();
        start_stop_btn->setText("Start");
        counted_time = std::chrono::duration_cast<std::chrono::seconds>(now_time - start_time);
    }
}

void STOPER::MainWindow::reset_slot()
{
    start_time = std::chrono::steady_clock::now();
    now_time = std::chrono::steady_clock::now();
    counted_time = std::chrono::duration_cast<std::chrono::seconds>(start_time - start_time);
    show_time();
}

void STOPER::MainWindow::update_time_lbl()
{
    now_time = std::chrono::steady_clock::now();
    show_time();
}

void STOPER::MainWindow::show_time()
{
    act_time->setText(QString::fromStdString(STOPER::UTILS::time_to_show(start_time, now_time, counted_time)));
}