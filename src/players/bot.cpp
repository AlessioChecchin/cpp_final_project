/**
 * @author Jacopo Toniolo
*/

#include "players/bot.h"
#include "players/action.h"
#include <iostream>
#include <set>

namespace prj
{
bot::bot() : player() {}

bot::bot(unsigned int balance) : player(balance) {}   

action bot::decision(const box* current_box, const std::set<action>& choices)
{
	std::cout << "Action bot" << std::endl;
	return action::NOTHING;
}

} // prj