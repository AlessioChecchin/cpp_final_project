# CMake version check.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Setting project name, version, and description.
project(final_project VERSION 1.0.0 DESCRIPTION "Final project of c++ programming laboratory")

# Enable c++11 standard.
set(CMAKE_CXX_STANDARD 11)

# Setting include directory. This directory contains all header files.
include_directories(include)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES
	src/main.cpp
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(final_project ${SOURCE_FILES})