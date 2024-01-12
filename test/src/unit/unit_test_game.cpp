#include "unit/unit_test_game.h"
#include "game.h"
#include "config.h"

#include <iostream>
#include <assert.h>

unit_test_game::unit_test_game(): test_suite{"unit_test_game"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_game::test_constructor, this)));
}

void unit_test_game::test_constructor()
{
	//testing constructor
	assert(("Failed to create game object", test_game_valid()));
}

bool test_game_valid()
{
	try
	{
		prj::game a(std::shared_ptr<prj::config>(new prj::config()));
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}