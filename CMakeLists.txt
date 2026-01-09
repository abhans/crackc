cmake_minimum_required(VERSION 3.16)

project(NotesApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick Qml)

qt_standard_project_setup()

# Defining the executable and C++ source files
qt_add_executable(appNotesApp
    src/main.cpp
    src/NoteModel.cpp
    src/NoteModel.h
    src/Note.h
)

# Defining the QML Module
qt_add_qml_module(appNotesApp
    URI "App"
    VERSION 1.0
    QML_FILES
        content/Main.qml
)

# Linking libraries
target_link_libraries(appNotesApp
    PRIVATE Qt6::Quick Qt6::Qml
)