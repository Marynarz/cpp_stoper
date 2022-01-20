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
        QLabel *label1;
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

    private slots:
        void close_app();
    };
};

#endif // WINDOW_H