cmake_minimum_required(VERSION 3.10)

# Include
#include(DoClangTidy.cmake)

# Use ccache
option(CCACHE_ENABLE
  "If the command ccache is avilable, use it for compile."
  ON)
find_program(CCACHE_EXE ccache)
if(CCACHE_EXE)
  if(CCACHE_ENABLE)
    message(STATUS "Enable ccache")
    if(CMAKE_C_COMPILER_LAUNCHER)
      set(CMAKE_C_COMPILER_LAUNCHER "${CMAKE_C_COMPILER_LAUNCHER}" "${CCACHE_EXE}")
    else()
      set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_EXE}")
    endif()
    if(CMAKE_CXX_COMPILER_LAUNCHER)
      set(CMAKE_CXX_COMPILER_LAUNCHER "${CMAKE_CXX_COMPILER_LAUNCHER}" "${CCACHE_EXE}")
    else()
      set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_EXE}")
    endif()
  endif()
endif()

# project
project(simple VERSION 0.1.0 LANGUAGES CXX)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# library dir
link_directories(/usr/local/fftw3/lib)

# packages
find_package(GTest REQUIRED)
include(GoogleTest)
include(CPack)
#include(CTest)
enable_testing()

# subdirectory
add_subdirectory(src/calc)
add_subdirectory(src/utility)
add_subdirectory(src/simple)
add_subdirectory(src/test)
add_subdirectory(src/benchmark)