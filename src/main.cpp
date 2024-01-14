#include <iostream>
#include <memory>

#include "config.h"
#include "game.h"

using namespace prj;

void print_usage();

int main(int argc, char* argv[])
{
	std::shared_ptr<config> my_config = nullptr;

	// argv[0]  = <executable name>
	// argv[1] = <first argument>
	if(argc == 2)
	{
		std::string target(argv[1]);

		if(target == "computer")
		{
			// Using default constructor.
			my_config = std::shared_ptr<config>(new config());
		}
		else if(target == "human")
		{
			// Using default constructor.
			// 1 human player, 3 bot.
			my_config = std::shared_ptr<config>(new config(1, 3));
		}
		else
		{
			print_usage();
		}

		if(my_config)
		{
			game my_game(my_config);
		}
	}
	else
	{
		print_usage();
	}

	return 0;
}

void print_usage()
{
	std::cout << "Error, invalid argument. Usage:" << std::endl;
	std::cout << "./<executable> human|computer" << std::endl; 
}