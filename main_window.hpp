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
#include "utils/number_ops.hpp"

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
        QPushButton *reset_btn;
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
        std::chrono::steady_clock::time_point start_time {};
        std::chrono::steady_clock::time_point now_time {};
        std::chrono::steady_clock::duration counted_time {};

    private slots:
        void close_app();
        void start_stop_slot();
        void reset_slot();
        void update_time_lbl();

    private:
        void show_time();
    };
};

#endif // WINDOW_H