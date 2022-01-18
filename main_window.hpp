#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <QMainWindow>

class QPushButton;

namespace STOPER
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow();

    private:
        QPushButton *m_button;
        QMenu *main_menu;
        QAction *exit;
        QMenu *filemenu;

        // create actions
        void createActions();

        //create menu
        void createMenus();

    private slots:
        void close_app();
    };
};

#endif // WINDOW_H