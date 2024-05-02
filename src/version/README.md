# Version

This component provides an easy way to pass build information like software/firmware version constants and variables, from the build system (i.e. CMake) to the project C/C++ code.

To use this component:

1. The build system must parse and replace the @SOMETHING@ variables according to build information, for example CMake could use **configure_file()** to make this variable replacement:

```cmake
# Set Version to code files
configure_file(
    ${CMAKE_SOURCE_DIR}/src/version/src/version.cpp.in
    ${CMAKE_SOURCE_DIR}/src/version/src/version.cpp
    @ONLY
)
```

2. Also, the build system must touch the version.cpp file each time a project build is requested, to ensure the GCC __DATE__ and __TIME__ variables are updated. For example, setup a pre-build target for that using CMake:

```cmake
# Touch version.cpp file to force update __DATE__ and __TIME__ and rebuild it
add_custom_target(update_version
    ${CMAKE_COMMAND} -E touch ${CMAKE_SOURCE_DIR}/src/version/src/version.cpp
)

# Setup the Pre-Build Targets as dependencies to run before the Build
add_dependencies(${PRJ_OUT_FILE}.elf update_version)
```
