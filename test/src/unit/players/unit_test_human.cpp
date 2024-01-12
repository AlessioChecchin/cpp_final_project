#include "../../../include/unit/players/unit_test_human.h"
#include "../../../../include/players/human.h"

#include <iostream>
#include <assert.h>

unit_test_human::unit_test_human(): test_suite{"unit_test_human"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_human::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_human::test_getters, this)));
	add_test(test("setters", std::bind(&unit_test_human::test_setters, this)));
	add_test(test("methods", std::bind(&unit_test_human::test_methods, this)));
}

void unit_test_human::test_constructor()
{
	//testing constructor
}

void unit_test_human::test_getters()
{
	//testing getters
}

void unit_test_human::test_setters()
{
	//testing setters
}

void unit_test_human::test_methods()
{
	//testing decision()
}