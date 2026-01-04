#include <QFont>
#include <QApplication>

#include "app/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFont font("JetBrains Mono");
    font.setPointSize(10);
    app.setFont(font);

    avi::app::MainWindow window;
    window.show();

    return app.exec();
}