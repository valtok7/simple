

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

add_library(utility STATIC
    utility.cpp
)
target_include_directories(utility
    PUBLIC ../include
)
if(CLANG_TIDY_EXE)
    set_target_properties(utility PROPERTIES CXX_CLANG_TIDY "${DO_CLANG_TIDY}" ) 
endif()
