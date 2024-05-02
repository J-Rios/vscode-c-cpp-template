
add_library(commons)

target_include_directories(commons
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(commons
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/commons.c
        ${CMAKE_CURRENT_LIST_DIR}/commons.h
)
