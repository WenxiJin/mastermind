cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

enable_testing()
include_directories(${PROJECT_SOURCE_DIR}/src)
set(gtest_SOURCE_DIR "${PROJECT_SOURCE_DIR}/googletest")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# unittest
add_executable(testfeedback testfeedback.cpp)
target_link_libraries(testfeedback gtest gtest_main libfeedback)
add_test(testfeedback testfeedback)
