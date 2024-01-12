#include "core/test_config.h"		//test_config is included, go uncomment macros to configure it
#include "core/test_suite.h"

#include "unit/unit_test_config.h"
#include "unit/unit_test_category.h"
#include "unit/unit_test_dice.h"
#include "unit/unit_test_contract.h"
#include "unit/unit_test_box.h"
#include "unit/unit_test_board.h"
#include "unit/unit_test_playground.h"
#include "unit/unit_test_game.h"

#include "unit/players/unit_test_human.h"
#include "unit/players/unit_test_bot.h"

#include "unit/building/unit_test_terrain.h"
#include "unit/building/unit_test_house.h"
#include "unit/building/unit_test_hotel.h"

#include <iostream>
#include <memory>

int main()
{

	std::vector<std::unique_ptr<test_suite>> tests;

	tests.push_back(std::unique_ptr<test_suite>(new unit_test_config()));
	//tests.push_back(std::unique_ptr<test_suite>(new unit_test_category())); // Test fail
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_dice()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_human()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_bot()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_terrain()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_house()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_hotel()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_contract()));

	tests.push_back(std::unique_ptr<test_suite>(new unit_test_box()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_board()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_playground()));
	tests.push_back(std::unique_ptr<test_suite>(new unit_test_game()));

	for(int i = 0; i < tests.size(); i++)
	{
		tests[i]->run_test_suite();
	}
	
	return 0;
}