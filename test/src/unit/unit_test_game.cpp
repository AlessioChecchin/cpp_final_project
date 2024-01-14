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
	//add_test(test("methods", std::bind(&unit_test_game::test_methods, this)));
}

void unit_test_game::test_constructor()
{
	//testing constructor
	assert(("Failed to create game object", test_game_valid(std::shared_ptr<prj::config>(new prj::config())) == true));

	assert(("Failed not to create game object", test_game_valid(nullptr) == false));
}

void unit_test_game::test_methods()
{
	//testing run()
	prj::game a(std::shared_ptr<prj::config>(new prj::config()));

	assert(("Failed not to create game object", try_run(a) == true));
}

bool test_game_valid(std::shared_ptr<prj::config> configuration)
{
	try
	{
		prj::game a(configuration);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool try_run(prj::game& game)
{
	try
	{
		game.run();
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}