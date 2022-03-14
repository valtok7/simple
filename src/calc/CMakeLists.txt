set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")
add_library(calc SHARED
    calc.cpp
)
target_include_directories(calc PUBLIC 
    ../include
    /usr/local/fftw3/include
)
set_target_properties(calc PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON COMPILE_FLAGS "${WARNING_FLAGS}" )
if(CLANG_TIDY_EXE)
    set_target_properties(calc PROPERTIES CXX_CLANG_TIDY "${DO_CLANG_TIDY}" ) 
endif()

target_link_libraries(calc PUBLIC fftw3)
