# Demo Qt6 Project : Notes App

Directory structure for a standard Qt6 "Notes App" project using CMake:

```text
Root/
├── CMakeLists.txt              # The main build configuration file
├── src/                        # All C++ source code (Backend)
│   ├── main.cpp                # Entry point: sets up the app and engine
│   ├── Note.h                  # Data structure (POD) for a Note
│   ├── NoteModel.h             # Header for the ListModel
│   └── NoteModel.cpp           # Implementation of the ListModel
└── content/                    # All QML and UI assets (Frontend)
    ├── Main.qml                # The main application window
    └── qtquickcontrols2.conf   # (Optional) Style configuration
```

## Source Directory (`src/`)
- **main.cpp:** This initializes the `QGuiApplication` and the `QQmlApplicationEngine`. It is also where you register your C++ types (like NoteModel) so QML can see them.

- **Note.h:** A lightweight header defining the raw data structure (struct `Note`). It has no logic, just data fields.

- **NoteModel.h:** The blueprint for your custom model. It defines the interface (functions like `addNote`, `rowCount`) and the signals.

- **NoteModel.cpp:** The actual logic. This file manages the QList of notes and handles the "mapping" between C++ data roles and QML names.

## QML Frontend Directory (`content/`)

This folder contains the "Face" of your application.

- **Main.qml:** The entry point for the UI. It defines the `ApplicationWindow` and instantiates the `NoteModel` we created in C++.

# Classes & Objects

## Note Data Object `Note.h`

This is the **"Plain Old Data (POD)"** structure. 

It doesn't need to inherit from `QObject` because it is just a **passive container** for information. This keeps memory footprint light.

## The Model Engine `NoteModel.h`

This class bridges the gap between C++ logic and the QML interface. 

With `Q_INVOKABLE` macro, it specifies that Qt's **meta-object system** which these functions can be called directly from JavaScript/QML.