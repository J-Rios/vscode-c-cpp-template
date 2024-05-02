
add_library(version)

target_include_directories(version
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src
)

target_sources(version
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src/version.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/version.h
)
