
### Project Libraries & Tools Dependencies ###

####################################################################################################

### Libraries To Fetch ###

message("Get/Update project dependencies, please wait...")

include(FetchContent)

####################################################################################################

### Libraries To Fetch ###

# SQueue
#FetchContent_Declare(
#    squeue
#    GIT_REPOSITORY ${CNI_LIBS}/generic/containers/squeue.git
#    GIT_TAG v1.0.0
#    SOURCE_DIR ${DIR_LIBDEP}/squeue
#)
#FetchContent_MakeAvailable(squeue)

#
# Add Here More Libraries...
# ...


####################################################################################################

### Tools To Fetch ###

# ELF File Analysis Tool
FetchContent_Declare(
    elfcheck
    GIT_REPOSITORY https://github.com/J-Rios/elfcheck
    GIT_TAG v1.0.0
    SOURCE_DIR ${DIR_DEPS_TOOL}/elfcheck
)
FetchContent_MakeAvailable(elfcheck)

#
# Add Here More Tools...
# ...

####################################################################################################
