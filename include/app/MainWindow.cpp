#include "app/MainWindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

namespace avi::app {

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) 
{
    setWindowTitle("AVI System");
    resize(800, 600);

    wCentralWidget = new QWidget(this);
    setCentralWidget(wCentralWidget);

    QVBoxLayout* layout = new QVBoxLayout(wCentralWidget);

    wLabel = new QLabel("Welcome to the AVI System!", wCentralWidget);
    wLabel->setAlignment(Qt::AlignCenter);
    
    layout->addWidget(wLabel);

    wCentralWidget->setLayout(layout);
}

}