# vscode-c-cpp-template

A basic C/C++ template CMake/Makefile project to work and debug with Visual Studio Code.

The "main" branch contains CMake project. In case you want to use a Makefile project approach, use the "makefile-project" branch.

## Notes

- Set/modify input arguments in "args" attribute of .vscode/launch.json file.
- Set/modify make targets to run in "command" attribute of .vscode/tasks.json file.
- To use it in Windows, you need a linux enviorment (for example WSL), set it as default terminal for vscode and also install "Remote - WSL" addon and re-open project directory in the remote WSL setup window (left-bottom green button to change it), then install C/C++ addon to WSL.
- Packages needed: build-essential, binutils, gcc, g++, make, gdb.
