#ifndef AVI_APP_MAINWINDOW_H
#define AVI_APP_MAINWINDOW_H

#include <QMainWindow>

namespace avi::app {

class MainWindow : public QMainWindow {
    Q_OBJECT
    Q_DISABLE_COPY(MainWindow)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;
};

}

#endif  // AVI_APP_MAINWINDOW_H