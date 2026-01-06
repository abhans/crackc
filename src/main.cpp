#include <iostream>
#include <QFont>
#include <QApplication>

#include "io/Logger.h"
#include "app/MainWindow.h"

using namespace avi;

io::Logger logger("logs/main.log");

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFont font("JetBrains Mono");
    font.setPointSize(10);
    app.setFont(font);

    app::MainWindow window;
    window.show();

    logger.log(io::Level::INFO, "Application has started.");

    return app.exec();
}