#include <QApplication>
#include "main_window.hpp"
#include "logger/logger.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    LOG::Logger::getInstance().addTrace("Dziala?");

    STOPER::MainWindow window;
    window.show();

    return app.exec();
}
