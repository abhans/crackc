cmake_minimum_required(VERSION 3.16)

project(crackc LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Enable Qt specific features
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ArUco Demo
add_executable(aruco src/aruco.cpp)
target_link_libraries(aruco ${OpenCV_LIBS})
# Qt5 Demo
add_executable(qt src/qt.cpp)
target_link_libraries(qt PRIVATE Qt5::Widgets)