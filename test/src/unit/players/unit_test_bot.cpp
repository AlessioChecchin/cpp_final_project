#include "unit/players/unit_test_bot.h"
#include "players/bot.h"

#include <iostream>
#include <assert.h>

unit_test_bot::unit_test_bot(): test_suite{"unit_test_bot"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_bot::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_bot::test_getters, this)));
	add_test(test("setters", std::bind(&unit_test_bot::test_setters, this)));
	add_test(test("methods", std::bind(&unit_test_bot::test_methods, this)));
}

void unit_test_bot::test_constructor()
{
	//testing constructor
}

void unit_test_bot::test_getters()
{
	//testing getters
}

void unit_test_bot::test_setters()
{
	//testing setters
}

void unit_test_bot::test_methods()
{
	//testing decision()
}