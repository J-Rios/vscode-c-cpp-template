
### Project Libraries & Tools Dependencies ###

####################################################################################################

### Libraries To Fetch ###

message("Get/Update project dependencies, please wait...")

include(FetchContent)

# Setup Project Dependecies Fetch Path variables
set(DIR_DEPS_LIB ${CMAKE_SOURCE_DIR}/deps/libraries)
set(DIR_DEPS_TOOL ${CMAKE_SOURCE_DIR}/deps/tools)

####################################################################################################

### Libraries To Fetch ###

# Example Library
#FetchContent_Declare(
#    examplelib
#    GIT_REPOSITORY https://github.com/J-Rios/examplelib
#    GIT_TAG v1.0.0
#    SOURCE_DIR ${DIR_LIBDEP}/examplelib
#)
#FetchContent_MakeAvailable(examplelib)

#
# Add Here More Libraries...
# ...

####################################################################################################

### Tools To Fetch ###

# Example Tool
#FetchContent_Declare(
#    exampletool
#    GIT_REPOSITORY https://github.com/J-Rios/exampletool
#    GIT_TAG v1.0.0
#    SOURCE_DIR ${DIR_DEPS_TOOL}/exampletool
#)
#FetchContent_MakeAvailable(exampletool)

#
# Add Here More Tools...
# ...

####################################################################################################
