#!/bin/bash

# Generate the build folder if it does not exist.
if [ ! -d "./build" ]; then 
	mkdir build
fi

# Change directory.
cd build

# Generate cmake if it does not exist.
#if [! -d "./CMakeFiles"]; then
#	cmake ..
#fi

# Build the project.
make

# Check result of make. If successful it runs the executable, otherwise logs an error.
if [ $? -eq 0 ]; then
	./final_project human
else
	echo "Build failed..."
fi