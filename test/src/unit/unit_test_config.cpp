#include "unit/unit_test_config.h"
#include "../../include/config.h"

#include <iostream>
#include <assert.h>

unit_test_config::unit_test_config(): test_suite{"unit_test_config"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_config::test_constructor, this)));
	add_test(test("category_config", std::bind(&unit_test_config::test_category_config, this)));
	add_test(test("getter", std::bind(&unit_test_config::test_getters, this)));
}

void unit_test_config::test_constructor()
{
	//testing default constructor
	prj::config a;
}

void unit_test_config::test_category_config()
{
	//testing categry__coonfig constructor
	//note: there is an implicit cast when comparing an unsigned int with a negative int
	prj::config::category_config a{"a", 0, 8};
	assert(("Failed to create category_config object a{\"a\", 0, 8}", a.name == "a"));
	assert(("Failed to create category_config object a{\"a\", 0, 8}", a.id == 0));
	assert(("Failed to create category_config object a{\"a\", 0, 8}", a.number == 8));

	prj::config::category_config b{"abcdefg", 2, -203};
	assert(("Failed to create category_config object b{\"abcdefg\", 2, -203}", b.name == "abcdefg"));
	assert(("Failed to create category_config object b{\"abcdefg\", 2, -203}", b.id == -1));
	assert(("Failed to create category_config object b{\"abcdefg\", 2, -203}", b.number == -203));

	prj::config::category_config c{"", 0, 8};
	assert(("Failed to create category_config object c{\"\", 0, 8}", c.name == ""));
	assert(("Failed to create category_config object c{\"\", 0, 8}", c.id == 0));
	assert(("Failed to create category_config object c{\"\", 0, 8}", c.number == 8));
	
	
}

void unit_test_config::test_getters()
{
	//testing getters
	prj::config a;

	assert(("Failed to get human_number_", a.get_human_number() == 0));
	assert(("Failed to get bot_number_", a.get_bot_number() == 4));
	assert(("Failed to get initial_budget_", a.get_initial_budget() == 100));
	assert(("Failed to get bonus_cycle_", a.get_bonus_cycle() == 20));
	assert(("Failed to get dice_number_", a.get_dice_number() == 2));
	assert(("Failed to get dice_faces_number_", a.get_dice_faces_number() == 6));
	assert(("Failed to get buy_land_possibility_bot_", a.get_buy_land_possibity_bot() == 0.25));
	assert(("Failed to get buy_house_possibility_bot_", a.get_buy_house_possibility_bot() == 0.25));
	assert(("Failed to get buy_hotel_possibility_bot_", a.get_buy_hotel_possibility_bot() == 0.25));
	assert(("Failed to get log_path_", a.get_log_path() == "./log.txt"));

	//testing category_config getter
	std::vector<prj::config::category_config> available_categories;
	prj::config::category_config economy{"economy", 0, 8};
	prj::config::category_config standard{"standard", 1, 10};
	prj::config::category_config luxury{"luxury", 2, 6};

	available_categories.push_back(economy);
	available_categories.push_back(standard);
	available_categories.push_back(luxury);

	assert(("Failed to get available_categories", a.get_available_categories() == available_categories));
}