cmake_minimum_required(VERSION 3.16)

# Initialize CMake project
project(avisys LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Find Qt (Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${OpenCV_INCLUDE_DIRS})

# Generate executables
add_executable(
    avisys
    src/app/main.cpp
    src/app/MainWindow.cpp
    src/app/MainWindow.h
)

# Link only core libraries
target_include_directories(avisys PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(avisys PRIVATE ${OpenCV_LIBS} Qt6::Widgets)

# Add subdirectories for the application and core libraries
add_subdirectory(src/app)
add_subdirectory(core)