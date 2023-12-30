#!/bin/bash

# Generate the build folder if it does not exist.
if [ ! -d "./build" ]; then 
	mkdir build
fi

# Change directory.
cd build

make

# Check result of make. If successful it runs the executable, otherwise logs an error.
if [ $? -eq 0 ]; then
	./test
else
	echo "Building test failed failed..."
fi