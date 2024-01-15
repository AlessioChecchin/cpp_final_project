#include "unit/unit_test_config.h"
#include "config.h"
#include "building/terrain.h"
#include "building/house.h"
#include "building/hotel.h"

#include <iostream>
#include <assert.h>

unit_test_config::unit_test_config(): test_suite{"unit_test_config"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_config::test_constructor, this)));
	add_test(test("getter", std::bind(&unit_test_config::test_getters, this)));
	add_test(test("category_config", std::bind(&unit_test_config::test_category_config, this)));
}

void unit_test_config::test_constructor()
{
	//testing default constructor
	assert(("Failed to create config object", test_config_valid() == true));

	assert(("Failed to create config object", test_config_valid(1, 2) == true));
}

void unit_test_config::test_getters()
{
	//testing getters
	prj::config a;
	prj::terrain* terrain;
	prj::house* house;
	prj::hotel* hotel;

	assert(("Failed to get human_number_", a.get_round_number() == 100));
	assert(("Failed to get human_number_", a.get_human_number() == 0));
	assert(("Failed to get bot_number_", a.get_bot_number() == 4));
	assert(("Failed to get initial_budget_", a.get_initial_budget() == 100));
	assert(("Failed to get bonus_cycle_", a.get_bonus_cycle() == 20));
	assert(("Failed to get dice_number_", a.get_dice_number() == 2));
	assert(("Failed to get dice_faces_number_", a.get_dice_faces_number() == 6));
	assert(("Failed to get buy_land_possibility_bot_", a.get_buy_building_possibility(terrain) == 0.25)); 		//Segmentation fault
	assert(("Failed to get buy_land_possibility_bot_", a.get_buy_building_possibility(house) == 0.25));			//Segmentation fault
	assert(("Failed to get buy_land_possibility_bot_", a.get_buy_building_possibility(hotel) == 0.25));			//Segmentation fault
	assert(("Failed to get log_path_", a.get_log_path() == "./log.txt"));

	prj::config b(1,3);

	assert(("Failed to get human_number_", b.get_round_number() == 100));
	assert(("Failed to get human_number_", b.get_human_number() == 1));
	assert(("Failed to get bot_number_", b.get_bot_number() == 3));
	assert(("Failed to get initial_budget_", b.get_initial_budget() == 100));
	assert(("Failed to get bonus_cycle_", b.get_bonus_cycle() == 20));
	assert(("Failed to get dice_number_", b.get_dice_number() == 2));
	assert(("Failed to get dice_faces_number_", b.get_dice_faces_number() == 6));
	assert(("Failed to get buy_land_possibility_bot_", b.get_buy_building_possibility(terrain) == 0.25));		//Segmentation fault
	assert(("Failed to get buy_land_possibility_bot_", b.get_buy_building_possibility(house) == 0.25));			//Segmentation fault
	assert(("Failed to get buy_land_possibility_bot_", b.get_buy_building_possibility(hotel) == 0.25));			//Segmentation fault
	assert(("Failed to get log_path_", b.get_log_path() == "./log.txt"));

	assert(("Failed not to get buy_land_possibility_bot_", a.get_buy_building_possibility(nullptr) == 0));

	//testing category_config getter
	assert(("Failed to get available_categories", try_get_available_categories(a)));
}

void unit_test_config::test_category_config()
{
	//testing category_config constructor
	//note: there is an implicit cast when comparing an unsigned int with a negative int
	prj::config::category_config a("a", 0, 8);
	assert(("Failed to create category_config object a", a.name == "a"));
	assert(("Failed to create category_config object a", a.id == 0));
	assert(("Failed to create category_config object a", a.number == 8));

	prj::config::category_config b("abcdefg", -1, -203);
	assert(("Failed to create category_config object b", b.name == "abcdefg"));
	assert(("Failed to create category_config object b", b.id == -1));
	assert(("Failed to create category_config object b", b.number == -203));

	prj::config::category_config c("", 0, 8);
	assert(("Failed to create category_config object c", c.name == ""));
	assert(("Failed to create category_config object c", c.id == 0));
	assert(("Failed to create category_config object c", c.number == 8));
}

bool test_config_valid()
{
	try
	{
		prj::config a;
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool test_config_valid(unsigned int human_number, unsigned int bot_number)
{
	try
	{
		prj::config a(human_number, bot_number);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool try_get_available_categories(const prj::config& a)
{
	try
	{
		a.get_available_categories();
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}