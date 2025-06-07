cmake_minimum_required(VERSION 3.10)

project(crackc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(main src/main.cpp)
# ArUco Demo
add_executable(aruco src/aruco.cpp)

target_link_libraries(main ${OpenCV_LIBS})
# ArUco Demo
target_link_libraries(aruco ${OpenCV_LIBS})