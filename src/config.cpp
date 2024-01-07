#include "config.h"

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
			{ 2, 4,  7 },
			{ 4, 8, 14 }
		},
		bot_number_{3},
		initial_budget_{100},
		bonus_cycle_{20},
		dice_number_{2},
		dice_faces_number_{6},
		buy_land_possibility_bot_{0.25},
		buy_house_possibility_bot_{0.25},
		buy_hotel_possibility_bot_{0.25},
		log_path_{"./log.txt"}
	{
		display_props_["box_angular"]  = " ";
		display_props_["box_start"]    = "P";
		display_props_["box_economy"]  = "E";
		display_props_["box_standard"] = "S";
		display_props_["box_luxury"]   = "L";
		display_props_["suf_house"]    = "*";
		display_props_["suf_hotel"]    = "^";
		display_props_["suf_player"]   = "%d";
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

	double config::get_buy_land_possibity_bot() const
	{
		return buy_land_possibility_bot_;
	}

	double config::get_buy_house_possibility_bot() const
	{
		return buy_house_possibility_bot_;
	}

	double config::get_buy_hotel_possibility_bot() const
	{
		return buy_hotel_possibility_bot_;
	}

	std::string config::get_log_path() const
	{
		return log_path_;
	}
}