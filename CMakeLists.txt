cmake_minimum_required(VERSION 3.16)

# Initialize CMake project
project(crackc LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Generate executables
add_executable(main src/main.cpp)