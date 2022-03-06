

add_library(calc SHARED
    calc.cpp
)
target_include_directories(calc PUBLIC 
    ../include
    /usr/local/fftw3/include
)
target_link_libraries(calc PUBLIC fftw3)