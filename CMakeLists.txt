# CMake version check.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Setting project name, version, and description.
project(final_project VERSION 1.0.0 DESCRIPTION "Final project of c++ programming laboratory")

# Enable c++11 standard.
set(CMAKE_CXX_STANDARD 11)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES
	src/main.cpp
	
	src/playground.cpp
	src/players/player.cpp
	src/players/bot.cpp
	src/players/human.cpp
	src/box.cpp
	src/board.cpp
	src/category.cpp
	src/contract.cpp
	src/config.cpp
	src/game.cpp

	src/building/building.cpp
	src/building/terrain.cpp
	src/building/house.cpp
	src/building/hotel.cpp

	src/dice.cpp
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(final_project ${SOURCE_FILES})

# Setting include directory. This directory contains all header files.
target_include_directories(final_project PUBLIC include)