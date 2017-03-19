cmake_minimum_required (VERSION 3.2)
project (MasterMindGame)
add_executable(MasterMindGame.o MasterMindGame.c)
set_property(TARGET MasterMindGame.o PROPERTY C_STANDARD 99)
