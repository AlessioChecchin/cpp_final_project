#!/bin/bash

# Generate the build folder if it does not exist.
if [ ! -d "./build" ]; then 
	mkdir build
fi

# Change directory.
cd build

# Generate cmake if it does not exist.
if [ ! -f "Makefile" ] || [ ! -f "cmake_install.cmake" ] || [ ! -f "CMakeCache.txt" ] || [ ! -d "CMakeFiles" ]; then
	cmake ..
fi

# Build the project.
make

# Check result of make. If successful it runs the executable, otherwise logs an error.
if [ $? -eq 0 ]; then
	./final_project human
else
	echo "Build failed..."
fi