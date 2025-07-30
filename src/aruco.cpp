#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>


cv::Mat generateArucoMarker(std::string path, cv::aruco::Dictionary arucoDict, int id, int size);
std::vector<int> detectArucoMarkers(cv::Mat img, cv::aruco::Dictionary arucoDict);

// Constants
const cv::aruco::Dictionary ARUCO_DICT = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

// ---------------------------------------------------- [ MAIN ENTRYPOINT ] ----------------------------------------------------
// This is the main function that will be executed when the program runs.

int main() {
    std::string path = "images";
    std::array<int, 10> markerIds {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Generate markers
    for (const auto& id : markerIds) {
        cv::Mat marker = generateArucoMarker(path, ARUCO_DICT, id, 250);
    }
    std::cout << "Marker generation is done." << std::endl;
    
    // Read the Demo image for detection
    cv::Mat img = cv::imread("images/arucodemo.jpg", cv::IMREAD_COLOR);

    std::vector<int> detectedIds = detectArucoMarkers(
        img,
        cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250)
    );
    
    std::cout << "Detected IDs:" << '\n';
    for (const auto& id : detectedIds) {
        std::cout << "> " << id << '\n';
    }
    
    return 0;
}

// ---------------------------------------------------- [ FUNCTION DEFINITIONS ] ----------------------------------------------------
// Function Definitions for ArUco Marker Generation and Detection


/**
 * Generate an ArUco marker image and save it to disk.
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


/**
 * Detects ArUco markers in the input image.
 *
 * If no dictionary is provided, defaults to DICT_6X6_250. Uses default
 * DetectorParameters for detection.
 *
 * @param img       The input image (`cv::Mat`) in which to detect markers.
 * @param arucoDict
 *     The ArUco dictionary to use. If empty, it will be replaced with the
 *     default `DICT_6X6_250` dictionary.
 *
 * @return `std::vector<int>`
 *     ID of the detected markers are returned in the form of an array.
 *
 * @note Currently, the function logs to `stdout/stderr` whether detection
 *       succeeded or failed, but does not annotate the image or raise on
 *       failure.
 */
std::vector<int> detectArucoMarkers(cv::Mat img, cv::aruco::Dictionary arucoDict) {
    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    // If no dictionary is given, get default
    if (arucoDict.bytesList.empty()) {
        arucoDict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    }
    // Parameters for the detector
    cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
    
    // ArUco Detector
    cv::aruco::ArucoDetector detector(arucoDict, detectorParams);
    detector.detectMarkers(img, markerCorners, markerIds, rejectedCandidates);

    if (markerCorners.empty()) {
        std::cerr << "No marker is detected!" << std::endl;
        return img;
    }

    std::cout << "Marker/s are detected" << std::endl;

    cv::Mat imgOut = img.clone();
    // Draw detected markers
    cv::aruco::drawDetectedMarkers(imgOut, markerCorners, markerIds);
    cv::imwrite("images/arucodetected.jpg", imgOut);

    return markerIds;
}