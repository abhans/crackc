#include <iostream>
#include <opencv2/opencv.hpp>

// Mixin: Printable
class Printable {
public:
    bool isPrinted = false;
    void print() {
        std::cout << "Printed..." << std::endl;
        isPrinted = true;
        return;
    }
};

// Mixin: Savable
class Savable {
public:
    bool isSaved = false;
    void save() {
        std::cout << "Saved..." << std::endl;
        isSaved = true;
        return;
    }
};

// Class: Document
//   + Printable (Mixin)
//   + Saveble (Mixin)
class Document : public Printable, public Savable {
public:
    // Document-specific methods here
};

int main() {
    Document doc;
    doc.print();  // From Printable mixin
    doc.save();   // From Savable mixin
    
	return 0;
}

// FeatureExtractor : Concrete Class
class FeatureExtractor {
public:
    void extractFeatures(const cv::Mat& image) {
        // Feature extraction logic
    }
};

// ImageProcessor : Composite Class
//    + FeatureExtractor
class ImageProcessor {
private:
    FeatureExtractor featureExtractor;

public:
    void processImage(const cv::Mat& image) {
        // Placeholder for image processing logic

        // Use FeatureExtractor to extract features
        featureExtractor.extractFeatures(image);
    }
};

// CameraSystem : Composite Class
//    + ImageProcessor
//    + FeatureExtractor
class CameraSystem {
private:
    ImageProcessor imageProcessor;

public:
    void captureAndProcess() {
        // Placeholder for image capture logic
        cv::Mat image;

        // Use imageProcessor to process the image
        imageProcessor.processImage(image);
    }
};