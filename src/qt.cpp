#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QPushButton button("Qt5 on WSL works!");
    button.show();
    return app.exec();
}
