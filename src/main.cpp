#include <iostream>
#include <memory>
#include "playground.h"

int main()
{
	std::cout << "Hello world";

	playground p;
	
	auto tmp = std::unique_ptr<player>(new player());
	tmp->set_name("Gino");

	p.add_player(std::move(tmp));
	auto v = p.get_players();

	for(auto it = v.begin(); it != v.end(); it++)
	{
		player& ref = it->get();
		std::cout << ref.get_name();
	}
	return 0;
}