#include "unit/players/unit_test_human.h"
#include "players/human.h"
#include "players/action.h"
#include "box.h"
#include "category.h"
#include <algorithm>

#include <iostream>
#include <assert.h>

unit_test_human::unit_test_human(): test_suite{"unit_test_human"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_human::test_constructor, this)));
	add_test(test("methods", std::bind(&unit_test_human::test_methods, this)));
}

void unit_test_human::test_constructor()
{
	//testing constructor
	assert(("Failed to create human object", test_human_valid() == true));

	assert(("Failed to create human object", test_human_valid(0) == true));
	assert(("Failed to create human object", test_human_valid(100) == true));
	assert(("Failed to create human object", test_human_valid(-1) == true));
}

void unit_test_human::test_methods()
{
	//testing decision()
	prj::human a;

	prj::category c("Standard", 0);
	prj::box* current_box(new prj::box(c));

	std::set<prj::action> choices;
	choices.emplace(prj::action::BUY);

	assert(("Failed to take a decision", try_decision(a, current_box , choices) == true));

	choices.emplace(prj::action::UPGRADE);
	choices.emplace(prj::action::STAY);
	choices.emplace(prj::action::SHOW);
	choices.emplace(prj::action::NOTHING);
	choices.emplace(prj::action::LOSE);

	//assert(("Failed to take a decision", try_decision(a, current_box , choices) == true));
}

bool test_human_valid()
{
	try
	{
		prj::human a;
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}
bool test_human_valid(unsigned int balance)
{
	try
	{
		prj::human a(balance);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool try_decision(prj::human& human, const prj::box* current_box, const std::set<prj::action>& choices)
{
	try
	{
		human.decision(current_box, choices);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}