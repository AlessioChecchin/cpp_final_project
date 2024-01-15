#include "unit/players/unit_test_bot.h"
#include "players/bot.h"
#include "config.h"

#include <iostream>
#include <assert.h>

unit_test_bot::unit_test_bot(): test_suite{"unit_test_bot"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_bot::test_constructor, this)));
	add_test(test("methods", std::bind(&unit_test_bot::test_methods, this)));
}

void unit_test_bot::test_constructor()
{
	//testing constructor
	assert(("Failed to create bot object", test_bot_valid(std::shared_ptr<prj::config>(new prj::config())) == true));

	assert(("Failed not to create bot object", test_bot_valid(nullptr) == false));

}

void unit_test_bot::test_methods()
{
	//testing decision()
	prj::bot a(std::shared_ptr<prj::config>(new prj::config()));

	prj::category c("Standard", 0);
	prj::box* current_box(new prj::box(c));

	std::set<prj::action> choices;
	choices.emplace(prj::action::BUY);

	assert(("Failed to take a decision", try_decision(a, current_box, choices) == true));

	choices.emplace(prj::action::UPGRADE);
	choices.emplace(prj::action::STAY);
	choices.emplace(prj::action::SHOW);
	choices.emplace(prj::action::NOTHING);
	choices.emplace(prj::action::LOSE);

	assert(("Failed to take a decision", try_decision(a, current_box, choices) == true));
}

bool test_bot_valid(std::shared_ptr<prj::config> configuration)
{
	try
	{
		prj::bot a(configuration);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool test_bot_valid(unsigned int balance, std::shared_ptr<prj::config> configuration)
{
	try
	{
		prj::bot a(balance, configuration);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool try_decision(prj::bot& bot, const prj::box* current_box, const std::set<prj::action>& choices)
{
	try
	{
		bot.decision(current_box, choices);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}