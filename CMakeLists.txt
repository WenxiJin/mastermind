# at least 2.8
cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
# project name
project (mastermind)
# source and header files
add_subdirectory(src)
# googletest framework
add_subdirectory(googletest)
# unittest based on googletest framework
add_subdirectory(test)
