cmake_minimum_required(VERSION 3.25)

project(avisys VERSION 0.1 LANGUAGES CXX)

# Modern C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Package Qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Package: OpenCV
find_package(OpenCV REQUIRED)

add_executable(avisys src/main.cpp)

target_include_directories(avisys PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(avisys PRIVATE ${OpenCV_LIBS} Qt6::Widgets)