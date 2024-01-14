/**
 * @author Jacopo Toniolo
*/

#include "players/human.h"
#include "players/action.h"

#include <iostream>

namespace prj
{

human::human() : player() {}
human::human(unsigned int balance) : player(balance) {}

action human::decision(const box* current_box, const std::set<action>& choices)
{
	// If he has only one choice it's returned.
	// No interaction is made.
	if(choices.size() == 1)
	{
		return *choices.begin();
	}

	if(choices.find(action::BUY) != choices.end())
	{
		std::cout << "Il terreno attuale e' libero, lo vuoi comprare?" << std::endl;

		if(wait_feedback() == 'y')
		{
			return action::BUY;
		}
	}
	else if(choices.find(action::UPGRADE) != choices.end())
	{

		std::cout << "Vuoi fare l'upgrade [" << current_box->get_contract()->get_building()->get_name() << "] ?" << std::endl;

		if(wait_feedback() == 'y')
		{
			return action::UPGRADE;
		}
	}

	return action::NOTHING;
}

char human::wait_feedback()
{
	std::string response;

	do 
	{
		std::cin >> response;
		std::cin.clear();

		if(response.empty() || (std::tolower(response[0]) != 'y' && std::tolower(response[0] != 'n')))
		{
			std::cout << "Risposta non valida" << std::endl;
		}

	}
	while(response.empty() || (std::tolower(response[0]) != 'y' && std::tolower(response[0] != 'n')));

	return std::tolower(response[0]);
}


} // prj