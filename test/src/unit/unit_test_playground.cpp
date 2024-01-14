#include "unit/unit_test_playground.h"
#include "playground.h"
#include "players/player.h"
#include "players/human.h"
#include "players/bot.h"
#include "config.h"

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
}

void unit_test_playground::test_constructor()
{
	//testing constructor
	assert(("Failed to create playground object", test_playground_valid(std::shared_ptr<prj::config>(new prj::config())) == true));

	assert(("Failed to create playground object", test_playground_valid(nullptr) == false));
}

void unit_test_playground::test_getters()
{
	//testing getters
	prj::playground a(std::shared_ptr<prj::config>(new prj::config()));
	
	assert(("Failed to get box 0 name", a.get_box_name(0) == "H8"));
	assert(("Failed to get box 1 name", a.get_box_name(1) == "H7"));
	assert(("Failed to get box 14 name", a.get_box_name(14) == "A1"));
	assert(("Failed to get box 27 name", a.get_box_name(27) == "G8"));

	assert(("Failed not to get box -1 name", try_get_box_names(a, -1) == false));
	assert(("Failed not to get box 28 name", try_get_box_names(a, 28) == false));
	assert(("Failed not to get box 100 name", try_get_box_names(a, 100) == false));
	assert(("Failed not to get box 35 name", try_get_box_names(a, 35) == false));
	
	std::shared_ptr<prj::player> b(new prj::human());
	std::shared_ptr<prj::player> c(new prj::bot(std::shared_ptr<prj::config>(new prj::config())));
	a.add_player(b);
	a.add_player(c);
	a.move_player(c, 4);

	assert(("Failed to get players_", try_get_players(a) == true));

	assert(("Failed to get player b box", try_get_player_box(a, b) == true));
	assert(("Failed to get player c box", try_get_player_box(a, c) == true));

	assert(("Failed not to get player nullptr box", try_get_player_box(a, nullptr) == false));

}

void unit_test_playground::test_methods()
{
	//testing add_player()
	prj::playground a(std::shared_ptr<prj::config>(new prj::config()));
	prj::playground b(std::shared_ptr<prj::config>(new prj::config()));

	std::shared_ptr<prj::player> c(new prj::human());
	std::shared_ptr<prj::player> d(new prj::human());
	std::shared_ptr<prj::player> e(new prj::bot(std::shared_ptr<prj::config>(new prj::config())));
	std::shared_ptr<prj::player> f(new prj::bot(std::shared_ptr<prj::config>(new prj::config())));
	
	std::shared_ptr<prj::player> g(new prj::human());

	assert(("Failing to add a player", try_add(a, c) == true));
	assert(("Failing to add a player", try_add(a, d) == true));
	assert(("Failing to add a player", try_add(b, e) == true));
	assert(("Failing to add a player", try_add(b, f) == true));
	
	assert(("Failing not to add a player", try_add(a, c) == false));
	assert(("Failing not to add a player", try_add(a, d) == false));
	assert(("Failing not to add a player", try_add(a, e) == false));
	assert(("Failing not to add a player", try_add(a, f) == false));
	assert(("Failing not to add a player", try_add(b, c) == false));
	assert(("Failing not to add a player", try_add(b, d) == false));
	assert(("Failing not to add a player", try_add(b, e) == false));
	assert(("Failing not to add a player", try_add(b, f) == false));

	assert(("Failing not to add a player", try_add(a, nullptr) == false));
	assert(("Failing not to add a player", try_add(b, nullptr) == false));

	//testing is_playing()
	assert(("Failing to determine that this player is playing", a.is_playing(c) == true));
	assert(("Failing to determine that this player is playing", a.is_playing(d) == true));
	assert(("Failing to determine that this player is playing", b.is_playing(e) == true));
	assert(("Failing to determine that this player is playing", b.is_playing(f) == true));
	
	assert(("Failing to determine that this player is playing", a.is_playing(e) == false));
	assert(("Failing to determine that this player is playing", a.is_playing(f) == false));
	assert(("Failing to determine that this player is playing", b.is_playing(c) == false));
	assert(("Failing to determine that this player is playing", b.is_playing(d) == false));

	assert(("Failing to determine that this player is playing", a.is_playing(g) == false));
	assert(("Failing to determine that this player is playing", b.is_playing(g) == false));

	assert(("Failing to determine that this player is playing", a.is_playing(nullptr) == false));
	assert(("Failing to determine that this player is playing", a.is_playing(nullptr) == false));
	// "== true" is there and "== false" is there instead of "!" for better readability

	//testing move_player()
	assert(("Failing to move a player", try_move(a, c, 11) == true));
	assert(("Failing to move a player", try_move(a, d, 0) == true));
	assert(("Failing to move a player", try_move(b, e, 0) == true));
	assert(("Failing to move a player", try_move(b, f, -12) == true));

	assert(("Failing not to move a player", try_move(a, g, 0) == false));
	assert(("Failing not to move a player", try_move(b, g, 0) == false));
	assert(("Failing not to move a player", try_move(a, nullptr, 0) == false));
	assert(("Failing not to move a player", try_move(b, nullptr, 0) == false));

	//testing remove_player()
	assert(("Failing not to remove a player", try_remove(a, e) == false));
	assert(("Failing not to remove a player", try_remove(a, f) == false));
	assert(("Failing not to remove a player", try_remove(b, c) == false));
	assert(("Failing not to remove a player", try_remove(b, d) == false));

	assert(("Failing not to remove a player", try_remove(a, nullptr) == false));
	assert(("Failing not to remove a player", try_remove(b, nullptr) == false));

	assert(("Failing to remove a player", try_remove(a, c) == true));
	assert(("Failing to remove a player", try_remove(a, d) == true));
	assert(("Failing to remove a player", try_remove(b, e) == true));
	assert(("Failing to remove a player", try_remove(b, f) == true));

	assert(("Failing not to remove a player", try_remove(a, c) == false));
	assert(("Failing not to remove a player", try_remove(a, d) == false));
	assert(("Failing not to remove a player", try_remove(b, e) == false));
	assert(("Failing not to remove a player", try_remove(b, f) == false));

	//testing number_players(), has_next_player()
	assert(("Failing to determine the number of players", a.number_players() == 0));
	assert(("Failing to determine the number of players", b.number_players() == 0));

	assert(("Failing to determine that there isn't a next player", a.has_next_player() == false));
	assert(("Failing to determine that there isn't a next player", b.has_next_player() == false));

	a.add_player(c);
	a.add_player(d);
	b.add_player(e);
	b.add_player(f);

	assert(("Failing to determine the number of players", a.number_players() == 2));
	assert(("Failing to determine the number of players", b.number_players() == 2));

	assert(("Failing to determine that there is a next player", b.has_next_player() == true));
	assert(("Failing to determine that there is a next player", b.has_next_player() == true));

	//testing next_player()
	assert(("Failing to get the next player", try_next_player(a)));
	assert(("Failing to get the next player", try_next_player(a)));
	assert(("Failing to get the next player", try_next_player(b)));
	assert(("Failing to get the next player", try_next_player(b)));

	//testing perform_action()
	assert(("Failing to perform action", try_perform_action(a, c) == true));
	assert(("Failing to perform action", try_perform_action(a, d) == true));
	assert(("Failing to perform action", try_perform_action(b, e) == true));
	assert(("Failing to perform action", try_perform_action(b, f) == true));

	assert(("Failing to perform action", try_perform_action(a, e) == false));
	assert(("Failing to perform action", try_perform_action(a, f) == false));
	assert(("Failing to perform action", try_perform_action(b, c) == false));
	assert(("Failing to perform action", try_perform_action(b, d) == false));

	assert(("Failing to perform action", try_perform_action(a, g) == false));
	assert(("Failing to perform action", try_perform_action(b, g) == false));

	assert(("Failing to perform action", try_perform_action(a, nullptr) == false));
	assert(("Failing to perform action", try_perform_action(a, nullptr) == false));
}

bool test_playground_valid(std::shared_ptr<prj::config> configuration)
{
	try
	{
		prj::playground a(configuration);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool try_get_players(const prj::playground& a)
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
bool try_get_box_names(const prj::playground& a, unsigned int position)
{
	try
	{
		a.get_box_name(position);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool try_get_player_box(const prj::playground& a, std::shared_ptr<prj::player> p)
{
	try
	{
		a.get_player_box(p);
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

bool try_next_player(prj::playground& a)
{
	try
	{
		a.next_player();
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool try_perform_action(prj::playground& a, std::shared_ptr<prj::player> p)
{
	try
	{
		a.perform_action(p);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}