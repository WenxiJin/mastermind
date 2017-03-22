# at least 2.8
cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
# project name
project (mastermind)
# enable c
enable_language(C)
# project version
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(SOURCE mastermind.c feedback.c feedback.h
  userguess.c userguess.h
  machineguess.c machineguess.h)
# build executable
add_executable(mastermind.o ${SOURCE})

set_property(TARGET mastermind.o PROPERTY C_STANDARD 99)
