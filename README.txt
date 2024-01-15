# Final project presentation
Final project of c++ programming laboratory, provided by the TonioloChecchin group.
Group members and program authors: Alessio Checchin, Giulio Cattelan, Jacopo Toniolo



# Project presentation

The project is a monopoly game.

The software can run matches with 4 bots and with 3 bots and 1 human.
To run the program to make a 4 bots match, run "./run.sh computer" or "./build/final_project computer", otherwise run "./run.sh human" or "./build/final_project human".
(More information about building and running the software later)

When running the program, the gaming automatically starts with no need to launch it through other commands.

When the game starts, some dice rolls are automatically thrown.
This is made in order to get an order to turn players (higher is first).
In case of a tie, the dices are withdrawn until there is a precise order.
Then the match starts with that same order.

In each monopoly game wins the only player who manages not to go bankrupt. Everyone else loses.
To avoid endless games, there is a limit of 100 rounds.
In this case, the winner is the player with more money. Everyone else loses. 

Each game also logs the actions made in a specific file (called log.txt), which can be found in the same directory of final_project (build).
There are already two samples in cpp_final_project directory: one done in a 1human/3bots game and the other one done in a 4bots game.
(The two samples are respectively named log_human.txt and log_computer.txt)



# Build project

In Linux you can run the program by either using the script run.sh or manually build and run the program.

	To build and run with run.sh, follow this instructions:

		- Open the cpp_final_project (the project root folder) folder in terminal
		- Run the project by running one of the following:
																			./run.sh human
																			./run.sh computer

	To manually build and run the program, follow this instructions:
	
		- Open the cpp_final_project (the project root folder) folder in terminal
		- Create a build folder by running: 								mkdir build
		- Enter the build folder by running: 								cd build
		- Setup the CMake enviroment and generate makefiles by running: 	cmake .. (CMakeLists.txt is placed in cpp_final_project directory)
		- Build the project by running: 									make
		- Run the project by running one of the following:
																			./final_project human
																			./final_project computer

In Windows you can only run the program by manually build and run the program.
(Windows compilation requires MingW, a C++ compiler translator, and needs to be installed)

	To do so, follow this instructions:

		- Open the cpp_final_project (the project root folder) folder in terminal
		- Create a build folder by running: 								mkdir build
		- Enter the build folder by running: 								cd build
		- Setup the CMake enviroment and generate makefiles by running: 	cmake .. -G "MingWMakefiles" (CMakeLists.txt is placed in cpp_final_project directory)
		- Build the project by running: 									make
		- Run the project by running one of the following:
																			.\final_project.exe human
																			.\final_project.exe computer



# Test presentation

The project also includes a test directory, which contains everything is needed to properly test every class and check their safety.



# Build tests

In Linux you can run the test program by either using the script run_tests.sh or manually build and run the test program.

	To build and run with run.sh, follow this instructions:

		- Open the  test folder in terminal (cpp_final_project/test)
		- Run the command: 													./run_tests.sh

	To manually build and run the program, follow this instructions:
	
		- Open the  test folder in terminal (cpp_final_project/test)
		- Create a build folder by running: 								mkdir build
		- Enter the build folder by running: 								cd build
		- Setup the CMake enviroment and generate makefiles by running: 	cmake .. (CMakeLists.txt is placed in cpp_final_project directory)
		- Build the project by running: 									make
		- Run the project by running: 										./test

In Windows you can only run the program by manually build and run the program.
(Windows compilation requires MingW, a C++ compiler translator, and needs too be installed)

	To do so, follow this instructions:

		- Open the  test folder in terminal (cpp_final_project/test)
		- Create a build folder by running: 								mkdir build
		- Enter the build folder by running: 								cd build
		- Setup the CMake enviroment and generate makefiles by running: 	cmake .. -G "MingWMakefiles" (CMakeLists.txt is placed in cpp_final_project directory)
		- Build the project by running: 									make
		- Run the project by running: 										.\test.exe
