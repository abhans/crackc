#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    // Example function to load and display an image
    void loadAndDisplayImage(const std::string &imagePath);

private:
    QWidget* centralWidget_;
    QVBoxLayout* layout_;
    QLabel* imageLabel_;
};

#endif // MAINWINDOW_H
