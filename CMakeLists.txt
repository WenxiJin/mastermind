cmake_minimum_required (VERSION 3.2)
project (mastermind)
include_directories(.)
set(SRC mastermind.c feedback.c feedback.h
  userguess.c userguess.h
  machineguess.c machineguess.h)
add_executable(mastermind.o ${SRC})
set_property(TARGET mastermind.o PROPERTY C_STANDARD 99)
