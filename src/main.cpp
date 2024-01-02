#include <iostream>
#include <memory>

#include "playground.h"
#include "player.h"


using namespace prj;

int main()
{
	std::cout << "Hello world";

	prj::playground p; // Todo: ambiguo senza prj::? 
	
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