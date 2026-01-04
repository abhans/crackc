#include "app/MainWindow.h"

namespace avi::app {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    
    setWindowTitle("AVI System");
    resize(800, 600);
}

}