cmake_minimum_required(VERSION 3.14)
project(StackMachine)

set(CMAKE_CXX_STANDARD 14)

add_executable(StackMachine main.cpp Instruction.hpp StackMachine.hpp Program.hpp Data.hpp)