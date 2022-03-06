

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)
add_library(calc SHARED ${SOURCE})
target_include_directories(calc PUBLIC ../include /usr/local/fftw3/include)
target_link_libraries(calc PUBLIC fftw3)