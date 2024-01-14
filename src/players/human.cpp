/**
 * @author Jacopo Toniolo
*/

#include "players/human.h"
#include "players/action.h"

#include <iostream>
#include <algorithm>

namespace prj
{

human::human() : player() {}
human::human(unsigned int balance) : player(balance) {}

action human::decision(const box* current_box, const std::set<action>& choices)
{
	// If he has only one choice it's returned.
	// No interaction is made.
	if(choices.size() == 1)
		return *choices.begin();

	// Check if a choice is specified.
	bool is_buy = choices.find(action::BUY) != choices.end();
	bool is_upgrade = choices.find(action::UPGRADE) != choices.end();
	bool is_show = choices.find(action::SHOW) != choices.end();

	// If is a buy action or upgrade action
	if(is_buy || is_upgrade)
	{
		char feedback;

		// Buy has priority over upgrade.
		if(is_buy)
		{
			feedback = wait_feedback("Vuoi comprare la proprieta'? [s/n/show] ");

			if(feedback == 's')
				return action::BUY;
		}
		else if(is_upgrade)
		{
			feedback = wait_feedback("Vuoi effettuare un upgrade'? [s/n/show]");

			if(feedback == 's')
				return action::UPGRADE;
		}
		
		// Show command can only be done when interacting with buy or upgrade.
		if(is_show && feedback == 'm')
		{
			return action::SHOW;
		}
	}

	return action::NOTHING;
}

char human::wait_feedback(const std::string& message)
{
	std::string response;

	bool is_valid = false;

	do 
	{
		std::cout << message;
		std::getline(std::cin, response);
		std::cin.clear();

		is_valid = response == "S" || response == "s" ||
				   response == "N"  || response == "n" ||
				   response == "show" || response == "SHOW";
		
		if(!is_valid)
		{
			std::cout << "[ERRORE] Risposta non valida!" << std::endl;
		}

	}
	while(!is_valid);

	if(response == "show")
		return 'm';
	
	return std::tolower(response[0]);
}


} // prj