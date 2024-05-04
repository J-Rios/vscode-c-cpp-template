
### CMake Toolchain Configuration Setup File ###

message("\n\nToolchain: ARM Cortex-M4")

# Set Custom Linker Script
set(LINKER_SCRIPT "")

# Setup CMake for Crosscompile ARM Cortex-M4
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CPU_FLAGS "--cpu Cortex-M4")
set(CMAKE_CROSSCOMPILING 1)

# Toolchain Compiler Tools
set(TOOLCHAIN_PREFIX "arm-none-eabi-")
set(CMAKE_C_COMPILER "${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}g++")
set(CMAKE_AR "${TOOLCHAIN_PREFIX}gcc-ar")

# Platform Common Flags
set(PLATFORM_COMMON_FLAGS "-mcpu=cortex-m4 -mthumb")
set(PLATFORM_COMMON_FLAGS "${PLATFORM_COMMON_FLAGS} -mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(PLATFORM_COMMON_FLAGS "${PLATFORM_COMMON_FLAGS} -fno-builtin")

# Platform C Compiler Flags
set(PLATFORM_C_FLAGS "${PLATFORM_COMMON_FLAGS}")

# Platform C++ Compiler Flags
set(PLATFORM_CXX_FLAGS "${PLATFORM_COMMON_FLAGS}")
set(PLATFORM_CXX_FLAGS "${PLATFORM_CXX_FLAGS} -fno-rtti -fno-exceptions")

# Platform Linker Flags
set(PLATFORM_FLAGS_LINKER "${PLATFORM_COMMON_FLAGS}")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER} --specs=nano.specs --specs=nosys.specs")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER} -Wl")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},-T${LINKER_SCRIPT}")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},-Map=${PROJECT_OUT}.map")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},-cref")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},--gc-sections")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},--defsym=malloc_getpagesize_P=0x1000")
set(PLATFORM_FLAGS_LINKER "${PLATFORM_FLAGS_LINKER},--print-memory-usage")
