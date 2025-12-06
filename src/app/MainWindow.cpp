#include "MainWindow.h"

#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      centralWidget_(new QWidget(this)),
      layout_(new QVBoxLayout()),
      imageLabel_(new QLabel())
{
    setWindowTitle("AVI System");

    imageLabel_->setAlignment(Qt::AlignCenter);
    layout_->addWidget(imageLabel_);

    centralWidget_->setLayout(layout_);
    setCentralWidget(centralWidget_);

    // Example: attempt to load and display an image at startup
    // (You can change the path to a valid image on your system)
    loadAndDisplayImage("/home/hans/crackc/images/marker0.png");
}

MainWindow::~MainWindow() = default;

void MainWindow::loadAndDisplayImage(const std::string &imagePath) {
    cv::Mat img = cv::imread(imagePath, cv::IMREAD_COLOR);
    if (img.empty()) {
        QMessageBox::warning(this, "Error", "Could not load image: " + QString::fromStdString(imagePath));
        return;
    }

    // Convert BGR (OpenCV) → RGB (Qt QImage)
    cv::Mat rgb;
    cv::cvtColor(img, rgb, cv::COLOR_BGR2RGB);

    QImage qimg(
        rgb.data,
        rgb.cols,
        rgb.rows,
        static_cast<int>(rgb.step),
        QImage::Format_RGB888
    );

    // Optionally: deep-copy to own the data (safer if rgb goes out of scope)
    QImage qimgCopy = qimg.copy();

    imageLabel_->setPixmap(QPixmap::fromImage(qimgCopy));
    resize(qimgCopy.size()); // adjust window size to image
}
