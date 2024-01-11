#include "core/test_config.h"		//test_config is included, go uncomment macros to configure it

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

int main()
{
	unit_test_config config_test;
	unit_test_category category_test;
	unit_test_dice dice_test;
	unit_test_human human_test;
	unit_test_bot bot_test;
	unit_test_terrain terrain_test;
	unit_test_house house_test;
	unit_test_hotel hotel_test;
	unit_test_contract contract_test;
	unit_test_box box_test;
	unit_test_board board_test;
	unit_test_playground playground_test;
	unit_test_game game_test;
	
	config_test.run_test_suite();
	category_test.run_test_suite();
	dice_test.run_test_suite();
	human_test.run_test_suite();
	bot_test.run_test_suite();
	terrain_test.run_test_suite();
	house_test.run_test_suite();
	hotel_test.run_test_suite();
	contract_test.run_test_suite();
	box_test.run_test_suite();
	board_test.run_test_suite();
	playground_test.run_test_suite();
	game_test.run_test_suite();
	
	return 0;
}