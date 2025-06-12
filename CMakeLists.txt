cmake_minimum_required(VERSION 3.16)

project(crackc LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Locate Package Dependencies
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
# ArUco Demo
add_executable(aruco src/aruco.cpp)
target_link_libraries(aruco ${OpenCV_LIBS})