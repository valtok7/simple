
# Compile Option
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

file(GLOB_RECURSE UNITTEST_SRC ../*_unittest.cpp)
add_executable(test_simple ${UNITTEST_SRC})
gtest_add_tests(TARGET test_simple)

target_link_libraries(test_simple PRIVATE calc utility gtest gmock pthread gtest_main)

