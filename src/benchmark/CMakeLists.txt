

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)
add_executable(bench ${SOURCE})
target_link_libraries(bench PRIVATE benchmark pthread calc)

