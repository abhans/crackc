#include <QApplication>

#include "app/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    avi::app::MainWindow window;
    window.show();

    return app.exec();
}