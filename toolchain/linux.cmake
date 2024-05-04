
### CMake Toolchain Configuration Setup File ###

message("Toolchain: Linux")

# Toolchain Compiler Tools
set(TOOLCHAIN_PREFIX "")
set(CMAKE_C_COMPILER "${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}g++")
set(CMAKE_AR "${TOOLCHAIN_PREFIX}gcc-ar")

# Platform Common Flags
set(PLATFORM_COMMON_FLAGS "")

# Platform C Compiler Flags
set(PLATFORM_C_FLAGS "${PLATFORM_COMMON_FLAGS}")

# Platform C++ Compiler Flags
set(PLATFORM_CXX_FLAGS "${PLATFORM_COMMON_FLAGS}")

# Platform Linker Flags
set(PLATFORM_FLAGS_LINKER "${PLATFORM_COMMON_FLAGS}")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER} -Wl")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},-Map=${PROJECT_OUT}.map")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},-cref")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},--gc-sections")
