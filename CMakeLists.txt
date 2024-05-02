### Project General CMakeLists File ###

####################################################################################################

### CMake General Configuration ###

cmake_minimum_required(VERSION 3.29)

# Disable CMake verify that compilers works properly
#set(CMAKE_C_COMPILER_WORKS 1)
#set(CMAKE_CXX_COMPILER_WORKS 1)

# Enable Assembly Files Compilation
#enable_language(ASM)

# Check for mandatory required tools
#find_package(Python REQUIRED)

####################################################################################################

### Project Configuration ###

# Project Name
project(myproject)

# Project Directory Paths
set(DIR_BIN ${CMAKE_SOURCE_DIR}/bin)
set(DIR_BUILD ${CMAKE_SOURCE_DIR}/build)
set(DIR_DOC ${CMAKE_SOURCE_DIR}/doc)
set(DIR_INC ${CMAKE_SOURCE_DIR}/include)
set(DIR_SRC ${CMAKE_SOURCE_DIR}/src)
set(DIR_LIB ${CMAKE_SOURCE_DIR}/lib)
set(DIR_CMAKE_TOOLCHAIN ${CMAKE_SOURCE_DIR}/cmake)
set(DIR_DEPS_LIB ${CMAKE_SOURCE_DIR}/deps/libraries)
set(DIR_DEPS_TOOL ${CMAKE_SOURCE_DIR}/deps/tools)

# Set variables for Programs
#set(PYTHON python3)

####################################################################################################

### Build Setup ###

# Configure the Standard Firmware Version
set(VERSION_X 1)
set(VERSION_Y 0)
set(VERSION_Z 0)

# Build this firmware as development version
set(VERSION_DEV true)

# Set Version String
set(VERSION v_${VERSION_X}_${VERSION_Y}_${VERSION_Z})
if(VERSION_DEV)
    set(VERSION ${VERSION}_dev)
endif(VERSION_DEV)

# Global Defines to be passed to Compiler (-DFLAG=X)
add_compile_definitions(
    #FLAG=1
    # ...
)

# Debug Build Target
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("Build Type: Debug")
    add_compile_definitions(DEBUG=1)
    add_compile_definitions(DEBUG_SEGGER_RTT)
    add_compile_definitions(DEBUG_LEVEL=4)
    add_compile_definitions(TEST)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

# Release Build Target
if(CMAKE_BUILD_TYPE MATCHES Release)
    message("Build Type: Release")
endif(CMAKE_BUILD_TYPE MATCHES Release)

# Firmware Type to build
if(VERSION_DEV)
    message("Version: Development")
else()
    message("Version: Standard")
endif(VERSION_DEV)

####################################################################################################

### Compile Configuration ###

# Common Warning Flags
set(COMMON_WARNING_FLAGS "-Wall -Wextra -Werror -Wpedantic -pedantic -Wshadow")
set(COMMON_WARNING_FLAGS "${COMMON_WARNING_FLAGS} -Wcast-align -Wconversion -Wparentheses")
set(COMMON_WARNING_FLAGS "${COMMON_WARNING_FLAGS} -Wmissing-declarations -Wredundant-decls")
set(COMMON_WARNING_FLAGS "${COMMON_WARNING_FLAGS} -Wimplicit-fallthrough=2")
set(COMMON_WARNING_FLAGS "${COMMON_WARNING_FLAGS} -fdump-tree-optimized -fstack-usage")

# C Warning Flags
set(C_WARNING_FLAGS "${COMMON_WARNING_FLAGS}")
set(C_WARNING_FLAGS "${C_WARNING_FLAGS} -Wmissing-prototypes -Wstrict-prototypes")

# C++ Warning Flags
set(CXX_WARNING_FLAGS "${COMMON_WARNING_FLAGS}")
set(CXX_WARNING_FLAGS "${COMMON_WARNING_FLAGS} -Wconditionally-supported -Wno-variadic-macros")

# Optimization Flags
set(OPTIMIZATION_FLAGS "-ffunction-sections -fdata-sections -static")
#set(OPTIMIZATION_FLAGS "{OPTIMIZATION_FLAGS} -flto")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(OPTIMIZATION_FLAGS "{OPTIMIZATION_FLAGS} -Og -ggdb -g")
endif()
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(OPTIMIZATION_FLAGS "{OPTIMIZATION_FLAGS} -Os")
endif()

# Include Toolchain Specific Configuration
include(${DIR_CMAKE_TOOLCHAIN}/CMakeToolchain_Linux.cmake)

set(CMAKE_C_FLAGS "${PLATFORM_C_FLAGS} ${C_WARNING_FLAGS} ${PLATFORM_FLAGS_LINKER}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c17")

set(CMAKE_CXX_FLAGS "${PLATFORM_CXX_FLAGS} ${CXX_WARNING_FLAGS} ${PLATFORM_FLAGS_LINKER}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

####################################################################################################

### Project Library Dependencies ###

# Run CMakeDeps to setup (get/update) project dependencies (libraries, tools, etc)
include(CMakeDeps.cmake)

####################################################################################################

### Directories and Sources To Use ###

# Set Project output file name
set(PROJECT_OUT ${PROJECT_NAME}_${VERSION})

# Sources files
set(SRC_FILES ${STARTUP_FILE} ${DIR_SRC}/main.cpp)

# Build executable binary
add_executable(${PROJECT_OUT}.elf ${SRC_FILES})

# Specify and Add Headers
target_include_directories(${PROJECT_OUT}.elf PUBLIC ${DIR_INC})

# Add subdirectories
add_subdirectory(src/commons)
add_subdirectory(src/version)
# ...

# Libraries for linkage (-lLIBRARY)
target_link_libraries(${PROJECT_OUT}.elf
    commons
    version
    # ...
)

####################################################################################################

### Build Target Properties ###

# Set build target properties
set_target_properties(${PROJECT_OUT}.elf
    PROPERTIES
    C_STANDARD 17
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

####################################################################################################

### Pre-Build Targets ###

# Write CMake Version variables into C/C++ code version file
configure_file(
    ${DIR_SRC}/version/src/version.cpp.in
    ${DIR_SRC}/version/src/version.cpp
    @ONLY
)

# Touch version.cpp file to force update __DATE__ and __TIME__ and rebuild it
add_custom_target(update_version
    ${CMAKE_COMMAND} -E touch ${DIR_SRC}/version/src/version.cpp
)

# Setup the Pre-Build Targets as dependencies to run before the Build
add_dependencies(${PROJECT_OUT}.elf
    update_version
    # ...
)

####################################################################################################

### Post-Build Targets ###

# Binary file build (file.bin)
add_custom_target(${PROJECT_OUT}.bin ALL
    COMMAND ${TOOLCHAIN_PREFIX}objcopy -O binary ${PROJECT_OUT}.elf ${PROJECT_OUT}.bin
    DEPENDS ${PROJECT_OUT}.elf)

# Symbols Table list file build (file.symtab)
add_custom_target(${PROJECT_OUT}.symtab ALL
    COMMAND ${TOOLCHAIN_PREFIX}nm -n -l -a ${PROJECT_OUT}.elf >> ${PROJECT_OUT}.symtab
    DEPENDS ${PROJECT_OUT}.elf)

# Show Build result memory size
add_custom_target(size_calculation ALL
    COMMAND ${TOOLCHAIN_PREFIX}size ${PROJECT_OUT}.elf
    DEPENDS ${PROJECT_OUT}.elf)

# Run Memory Usage Check Analysis Script
#add_custom_target(memory_usage_analysis ALL
#    COMMAND ${DIR_TOOLS}/memory_check ${DIR_BUILD} ${DIR_BUILD}/${PROJECT_OUT}.elf
#    DEPENDS ${PROJECT_OUT}.elf)

####################################################################################################
