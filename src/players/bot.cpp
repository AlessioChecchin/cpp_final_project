/**
 * Bot implementation.
 * 
 * @author Jacopo Toniolo
*/

#include "players/bot.h"

#include <iostream>
#include <set>

#include "players/action.h"
#include "dice.h"

namespace prj
{

bot::bot(unsigned int balance, std::shared_ptr<config> configuration) : player(balance)
{
	if(!configuration)
	{
		throw std::invalid_argument("Invalid configuration file");
	}

	configuration_ = configuration; 
}   

action bot::decision(const box* current_box, const std::set<action>& choices)
{
	// If he has only one choice it's returned.
	if(choices.size() == 1)
	{
		return *choices.begin();
	}

	if(choices.find(action::BUY) != choices.end())
	{
		double possibility = configuration_->get_buy_building_possibility(current_box->get_contract()->get_building());
		
		if(possibility > 0)
		{
			int possibile_faces = (1.0 / possibility);

			dice generator(possibile_faces);

			// The possibility of getting 1 from in [1, possible_faces] is exactly "possibility".
			if(generator.roll() == 1)
			{
				return action::BUY;
			}
		}
	}
	else if(choices.find(action::UPGRADE) != choices.end())
	{
		// We know is upgradable.
		std::unique_ptr<building> upgraded = current_box->get_contract()->get_building()->upgrade();

		double possibility = configuration_->get_buy_building_possibility(upgraded.get());
		
		if(possibility > 0)
		{
			int possibile_faces = (1.0 / possibility);

			dice generator(possibile_faces);

			// The possibility of getting 1 from in [1, possible_faces] is exactly possibility.
			if(generator.roll() == 1)
			{
				return action::UPGRADE;
			}
		}
	}

	// With multiple choices we always can do nothing.
	return action::NOTHING;
}

} // prj