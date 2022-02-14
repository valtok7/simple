

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)
add_library(utility STATIC ${SOURCE})
target_include_directories(utility
    PUBLIC ../include
    )
