
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

add_library(calc SHARED
    calc.cpp
)
target_include_directories(calc PUBLIC 
    ../include
    /usr/local/fftw3/include
)
target_link_libraries(calc PUBLIC fftw3)