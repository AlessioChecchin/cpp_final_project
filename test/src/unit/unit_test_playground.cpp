#include "../../include/unit/unit_test_playground.h"
#include "../../../include/playground.h"
#include "../../../include/players/player.h"
#include "../../../include/players/human.h"
#include "../../../include/players/bot.h"
#include "../../../include/config.h"

#include <iostream>
#include <assert.h>
#include <memory>
#include <stdexcept>

unit_test_playground::unit_test_playground(): test_suite{"unit_test_playground"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_playground::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_playground::test_getters, this)));
	add_test(test("methods", std::bind(&unit_test_playground::test_methods, this)));
	add_test(test("operators", std::bind(&unit_test_playground::test_operators, this)));
}

void unit_test_playground::test_constructor()
{
	//testing constructor
	assert(("Failed to create playground object", test_playground_valid()));
}

void unit_test_playground::test_getters()
{
	//testing getters
	prj::playground a(std::shared_ptr<prj::config>(new prj::config()));
	assert(("Failed to get players_", try_get(a)));
}

void unit_test_playground::test_methods()
{
	//testing add_player()
	prj::playground a(std::shared_ptr<prj::config>(new prj::config()));
	
	//assert(("Failing to add a player", try_add(a, new human())));		//To complete!!!
	//assert(("Failing to add a player", try_add(a, new human())));
	//assert(("Failing to add a player", try_add(a, new bot())));
	//assert(("Failing to add a player", try_add(a, new bot())));

	//assert(("Failed to get players_", try_get(a)));

	//testing is_playing()
	//assert(("Failing to determine that this player is playing", a.is_playing(new human()) == true));	//To complete!!!
	//assert(("Failing to determine that this player is playing", a.is_playing(new bot()) == true));
	// "== true" is there for better readability

	//assert(("Failing to determine that this player is not playing", a.is_playing(new human()) == false));
	//assert(("Failing to determine that this player is not playing", a.is_playing(new bot()) == false));
	// "== false" is there instead of "!" for better readability

	//testing move_player()
	//assert(("Failing to move a player", a.try_move(new human(), 1)));		//To complete!!!
	//assert(("Failing to move a player", a.try_move(new human(), 11)));
	//assert(("Failing to move a player", a.try_move(new bot(), -5)));
	//assert(("Failing to move a player", a.try_move(new bot(), 0)));

	//testing remove_player()
	//assert(("Failing to remove a player", try_remove(a, new human())));		//To complete!!!
	//assert(("Failing to remove a player", try_remove(a, new human())));
	//assert(("Failing to remove a player", try_remove(a, new bot())));
	//assert(("Failing to remove a player", try_remove(a, new bot())));

	//assert(("Failed to get players_", try_get(a)));

}

void unit_test_playground::test_operators()
{
	//testing operator<<
}

bool test_playground_valid()
{
	try
	{
		prj::playground a(std::shared_ptr<prj::config>(new prj::config()));
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool try_get(prj::playground& a)	//add const reference!!! 
{
	try
	{
		a.get_players();
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool try_add(prj::playground& a, std::shared_ptr<prj::player> p)
{
	try
	{
		a.add_player(p);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool try_move(prj::playground& a, std::shared_ptr<prj::player> p, int steps)
{
	try
	{
		a.move_player(p, steps);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool try_remove(prj::playground& a, std::shared_ptr<prj::player> p)
{
	try
	{
		a.remove_player(p);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}