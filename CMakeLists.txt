cmake_minimum_required(VERSION 3.10)
project(simple VERSION 0.1.0 LANGUAGES CXX)

find_package(GTest REQUIRED)
include(GoogleTest)
include(CPack)
#include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src/calc)
add_subdirectory(src/utility)
add_subdirectory(src/simple)
add_subdirectory(src/test)
