/**
 * Config implementation.
 * 
 * @author Alessio Checchin
*/

#include "config.h"
#include "players/action.h"
#include "category.h"
#include "building/building.h"

#include "building/terrain.h"
#include "building/house.h"
#include "building/hotel.h"

#include <string>


namespace prj
{
	config::config(): 
		buy_prices_{
			{
				{ 6, 10, 20 },
				{ 3,  5, 10 },
				{ 3,  5, 10 }
			}
		},
		stay_prices_{
			{ 0, 0,  0 },
			{ 2, 4,  7 },
			{ 4, 8, 14 }
		},
		round_number_{10}, /// !!!!! da modificare
		human_number_{0},
		bot_number_{4},
		initial_budget_{100},
		bonus_cycle_{20},
		dice_number_{2},
		dice_faces_number_{6},
		log_path_{"./log.txt"},
		available_categories_{}
	{
		display_props_["box_angular"]  = "";
		display_props_["box_start"]    = "P";
		display_props_["box_economy"]  = "E";
		display_props_["box_standard"] = "S";
		display_props_["box_luxury"]   = "L";
		display_props_["suf_terrain"]  = "";
		display_props_["suf_house"]    = "*";
		display_props_["suf_hotel"]    = "^";
		display_props_["suf_player"]   = "%d";

		category_config economy{"economy", 0, 8};
		category_config standard{"standard", 1, 10};
		category_config luxury{"luxury", 2, 6};

		available_categories_.push_back(economy);
		available_categories_.push_back(standard);
		available_categories_.push_back(luxury);

		buy_possibility_[terrain().get_id()] = 0.25;
		buy_possibility_[house().get_id()] = 0.25;
		buy_possibility_[hotel().get_id()] = 0.25;
	}

	config::config(unsigned int human_number, unsigned int bot_number): config() // delegating constructor.
	{
		human_number_ = human_number;
		bot_number_ = bot_number;
	}


	unsigned int config::get_round_number() const
	{
		return round_number_;
	}

	unsigned int config::get_human_number() const
	{
		return human_number_;
	}

	unsigned int config::get_bot_number() const
	{
		return bot_number_;
	}

	unsigned int config::get_initial_budget() const
	{
		return initial_budget_;
	}

	unsigned int config::get_bonus_cycle() const
	{
		return bonus_cycle_;
	}

	unsigned int config::get_dice_number() const
	{
		return dice_number_;
	}

	unsigned int config::get_dice_faces_number() const
	{
		return dice_faces_number_;
	}

	double config::get_buy_building_possibility(const building* to_buy) const
	{
		if(!to_buy)
		{
			return 0;
		}

		if(buy_possibility_.find(to_buy->get_id()) != buy_possibility_.end())
		{
			return buy_possibility_.at(to_buy->get_id());
		}

		return 0;
	}

	std::string config::get_display_prop(const std::string& prop_name) const
	{
		if(display_props_.find(prop_name) != display_props_.end())
		{
			return display_props_.at(prop_name);
		}

		return "";
	}

	std::string config::get_log_path() const
	{
		return log_path_;
	}

	std::vector<config::category_config> config::get_available_categories() const
	{
		return available_categories_;
	}

	int config::get_action_cost(action performed_action, const category building_category, const building* current_building) const
	{
		if(!current_building)
		{
			return 0;
		}

		int x = building_category.get_id();
		int y = current_building->get_id();

		if(performed_action == action::BUY || performed_action == action::UPGRADE)
		{
			if(y >= 0 && y <= buy_prices_.size())
			{
				if(x >= 0 && x <= buy_prices_[y].size())
				{
					return buy_prices_[y][x];
				}
			}
		}
		else if(performed_action == action::STAY)
		{
			if(y >= 0 && y <= stay_prices_.size())
			{
				if(x >= 0 && x <= stay_prices_[y].size())
				{
					return stay_prices_[y][x];
				}
			}
		}

		return 0;
	}
}