#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H
#define LOGF(x) LOG::Logger::getInstance()->addTrace(x)

#include <QMainWindow>
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QMenuBar>
#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include "logger/logger.hpp"

class QPushButton;

namespace STOPER
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow();

    private:
        // main window
        QWidget *widget;
        QGridLayout *layout;
        QLabel *act_time;
        QPushButton *start_stop_btn;
        QAction *start_stop_action;
        QTimer *timer;
        // create layout
        void createLayout();

        // menu
        QMenu *main_menu;
        QAction *exit;
        QMenu *filemenu;

        // create actions
        void createActions();

        // create menu
        void createMenus();

        bool is_started;
        int secs;

    private slots:
        void close_app();
        void start_stop_slot();
        void update_time_lbl();
    };
};

#endif // WINDOW_H