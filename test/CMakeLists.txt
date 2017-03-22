cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

enable_testing()
# access header files inside src folder
include_directories(${PROJECT_SOURCE_DIR}/src)
# for googletest header files
set(gtest_SOURCE_DIR "${PROJECT_SOURCE_DIR}/googletest")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# unittest
# NOTE: test files are named in cpp since googletest is a c++
add_executable(testfeedback testfeedback.cpp)
target_link_libraries(testfeedback gtest gtest_main libfeedback)
add_test(testfeedback testfeedback)
