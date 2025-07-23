cmake_minimum_required(VERSION 3.16)

# Initialize CMake project
project(crackc LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Locate package dependencies
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

# Generate executables
add_executable(aruco src/aruco.cpp)
add_executable(main src/main.cpp)

# Link the necessary libraries to executables
target_link_libraries(aruco ${OpenCV_LIBS}) 
target_link_libraries(main ${OpenCV_LIBS}) 