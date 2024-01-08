#include <iostream>
#include <memory>

#include "playground.h"
#include "player.h"
#include "config.h"

//Temp
#include "dice.h"


using namespace prj;

int main()
{

	//dice myDice(100);
	//for(int i=0; i<100; i++)
	//	std::cout << myDice.roll() << std::endl;

	std::cout << "Hello world";

	playground p(std::shared_ptr<config>(new config())); // ambiguo senza prj::? Commentando linea 6 in player.h funziona
	
	auto tmp = std::unique_ptr<player>(new player());
	tmp->set_name("Gino");

	std::cout << tmp->get_name();

	p.add_player(std::move(tmp));
	auto v = p.get_players();

	for(auto it = v.begin(); it != v.end(); it++)
	{
		std::shared_ptr<player> ref = *it;

		if(ref->get_name() == "Gino")
		{
			p.remove_player(ref);
			std::cout << "Removed" << ref->get_name();
		}

		std::cout << ref->get_name();
	}

	
	return 0;
}