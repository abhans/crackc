#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/aruco_detector.hpp>

// Function Signatures
cv::Mat generateArucoMarker(std::string path, cv::aruco::Dictionary arucoDict, int id, int size);

// Constants
const cv::aruco::Dictionary ARUCO_DICT = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

int main() {
    std::string path = "images";
    std::array<int, 10> markerIds {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Generate markers
    for (const auto& id : markerIds) {
        cv::Mat marker = generateArucoMarker(path, ARUCO_DICT, id, 250);
    }
    std::cout << "Marker generation is done." << std::endl;
    return 0;
}

/**
 * @brief Generate an ArUco marker image and save it to disk.
 *
 * This function creates a square marker image using OpenCV's ArUco module.
 * If the provided dictionary is empty, it defaults to DICT_6X6_250.
 * The marker is generated with the specified ID and pixel size, then saved
 * as "marker<id>.png" in the given folder.
 *
 * @param path      Folder path where the marker image will be saved.
 * @param arucoDict ArUco dictionary to use; if empty, defaults to DICT_6X6_250.
 * @param id        Marker ID (index within the dictionary).
 * @param size      Side length of the marker image in pixels.
 * @return          The generated marker as a cv::Mat.
 */
cv::Mat generateArucoMarker(std::string path, cv::aruco::Dictionary arucoDict, int id, int size) {
    
    // If no dictionary is given, get default
    if (arucoDict.bytesList.empty()) {
        arucoDict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    }
    
    cv::Mat marker;

    cv::aruco::generateImageMarker(arucoDict, id, size, marker, 1);
    
    std::string outPath = path + "/marker" + std::to_string(id) + ".png";
    cv::imwrite(outPath, marker);
    std::cout << "Marker saved to: " << outPath << '\n';
    
    return marker;
}