

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)
AUX_SOURCE_DIRECTORY(../utility SOURCE)
message(${SOURCE})
add_executable(test_utility ${SOURCE})
# add_test(NAME test_utility COMMAND test_utility)
gtest_add_tests(TARGET test_utility)

target_link_libraries(test_utility PRIVATE utility gtest gmock pthread gtest_main)

