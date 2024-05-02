# vscode_c_skelly

A basic C/C++ template CMake/Makefile project to work and debug with Visual Studio Code.

The **"master"** branch contains CMake project. In case you want to use a Makefile project approach, use the **"makefile-project"** branch.

## Notes

- Launch **"Build & Compile"** by pressing **F7** key.

- Launch **"Run & Debug"** by pressing **Ctrl+F5** key.

- Modify the project build setup by modifying the *CMakeLists.txt* file.

- The project is setup to automatically download required project dependencies (as external libraries or tools) by CMake FetchContent feature. Setup project dependencies in the **"CMakeDeps.cmake"** file. The dependencies will be download and stored in the **"deps/"** directory.

- Packages needed in Linux: build-essential, binutils, gcc, g++, make, gdb.
