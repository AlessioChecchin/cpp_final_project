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
	std::cout << "Human action perform" << std::endl;

	return action::NOTHING;
}

} // prj