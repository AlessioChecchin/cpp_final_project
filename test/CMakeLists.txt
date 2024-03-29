# CMake version check.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Setting project name, version, and description.
project(test_final_project VERSION 1.0.0 DESCRIPTION "Tests for c++ final project")

# Enable c++11 standard.
set(CMAKE_CXX_STANDARD 11)

# Getting parent directory. Here we assume that the parent directory is present.
cmake_path(GET PROJECT_SOURCE_DIR PARENT_PATH PARENT_DIR)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES
	./src/test_runner.cpp
	
	./src/core/test.cpp
	./src/core/test_suite.cpp

	./src/unit/unit_test_config.cpp
	./src/unit/unit_test_category.cpp
	./src/unit/unit_test_dice.cpp
	./src/unit/unit_test_contract.cpp
	./src/unit/unit_test_box.cpp
	./src/unit/unit_test_board.cpp

	./src/unit/unit_test_playground.cpp
	./src/unit/unit_test_game.cpp

	./src/unit/players/unit_test_human.cpp
	./src/unit/players/unit_test_bot.cpp

	./src/unit/building/unit_test_terrain.cpp
	./src/unit/building/unit_test_house.cpp
	./src/unit/building/unit_test_hotel.cpp

	./src/unit/logger/unit_test_logger.cpp

	# In order to test a class it must be added here.
	${PARENT_DIR}/src/board.cpp
	${PARENT_DIR}/src/box.cpp
	${PARENT_DIR}/src/category.cpp
	${PARENT_DIR}/src/config.cpp
	${PARENT_DIR}/src/contract.cpp
	${PARENT_DIR}/src/dice.cpp
	${PARENT_DIR}/src/game.cpp
	${PARENT_DIR}/src/logger/logger.cpp
	${PARENT_DIR}/src/playground.cpp
	${PARENT_DIR}/src/players/bot.cpp
	${PARENT_DIR}/src/players/human.cpp
	${PARENT_DIR}/src/players/player.cpp
	${PARENT_DIR}/src/building/building.cpp
	${PARENT_DIR}/src/building/hotel.cpp
	${PARENT_DIR}/src/building/house.cpp
	${PARENT_DIR}/src/building/terrain.cpp
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(test ${SOURCE_FILES})

# Setting include directory. This directory contains all header files.
target_include_directories(test PUBLIC ${PARENT_DIR}/include include)