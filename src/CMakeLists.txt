cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
# enable c
enable_language(C)
# project version
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(SOURCE mastermind.c
  userguess.c userguess.h
  machineguess.c machineguess.h)

# add library
add_library(libfeedback feedback.c)
set_property(TARGET libfeedback PROPERTY C_STANDARD 99)

add_library(libuserguess userguess.c)
set_property(TARGET libuserguess PROPERTY C_STANDARD 99)

add_library(libmachineguess machineguess.c)
set_property(TARGET libmachineguess PROPERTY C_STANDARD 99)

# build executable
add_executable(mastermind.o ${SOURCE})
target_link_libraries(mastermind.o libfeedback libuserguess libmachineguess)
set_property(TARGET mastermind.o PROPERTY C_STANDARD 99)
