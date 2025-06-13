# Cracking C/C++

I've used the C programming language several times on my projects (for embedded and FPGA programming courses that I've taken)

I always wanted to explore C and C++ deeper so that I can become a better programmer and also a better engineer.

This repository is created to store my practices on C language including various `.c` and `.cpp` files and possibly few projects that I've worked on.
You can find the main scripts at `src` directory.

I've also included notes on my studying sessions at `docs` that includes notes on the first chapter of the book titled `The C Programming Language`.
For the rest of the notes, contact me. I will consider it.

You might also find some C++ scripts here in there, mostly because I like to use both when prototyping.

## CMake Configuration

TO prevent Visual Studio Code to rebuild at save, it should be disabled in `.vscode/setting.json`:

```jsonc
{
  // Other settings...
  "cmake.configureOnOpen": false,
  "cmake.configureOnEdit": false,
  "cmake.useProjectStatusView": false
}
```

* `configureOnOpen: false` stops it from configuring on folder open.
* `configureOnEdit: false` stops it from running on save edits.
* `useProjectStatusView: false` (optional) disables UI prompts if not needed.

## Manually Building with CMake

To build the project, a `build` directory is needed in the root of the project directory:

```bash
mkdir -p build
```

To configure the CMake to generate faster and reliable, it should be configured through available flags:

```bash
# Configure (generate build system)
cmake -DCMAKE_BUILD_TYPE=Debug -B build
```

CMake configuration process can be seen in the terminal:

```bash
-- The CXX compiler identification is GNU 15.1.1
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/sbin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenCV: /usr (found version "4.11.0")
-- Configuring done (1.6s)
-- Generating done (0.0s)
-- Build files have been written to: /home/abhans/crackc/build
```

Finally, source code can be built from the **root** directory (crackc):

```bash
cmake --build build --config Debug
```

The build process can be seen in the terminal:

```bash
[ 50%] Building CXX object CMakeFiles/aruco.dir/src/aruco.cpp.o
[100%] Linking CXX executable aruco
[100%] Built target aruco
```

## Running the Executables

Resulting executables from the build can be found at `build/<FILENAME>.cpp` and be executed:

```bash
./build/aruco
./build/main
```
