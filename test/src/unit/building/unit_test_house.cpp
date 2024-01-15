/**
 * Implementation of house class unit test.
 * unit_test_house implementation.
 * 
 * @author Giulio Cattelan
*/

#include "unit/building/unit_test_house.h"
#include "building/house.h"

#include <iostream>
#include <assert.h>

unit_test_house::unit_test_house(): test_suite{"unit_test_house"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_house::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_house::test_getters, this)));
	add_test(test("methods", std::bind(&unit_test_house::test_methods, this)));
}

void unit_test_house::test_constructor()
{
	//testing default constructor
	prj::house a;

	assert(("Failing to create house object a:", a.get_name() == "house"));
	assert(("Failing to create house object a:", a.get_id() == 1));
}

void unit_test_house::test_getters()
{
	//testing getters
	prj::house a;

	assert(("Failing to create house object a:", a.get_name() == "house"));
	assert(("Failing to create house object a:", a.get_id() == 1));
}

void unit_test_house::test_methods()
{
	//testing upgrade()
	prj::house a;

	assert(("Failing to upgrade the object (it shouldn't be possible)", a.upgrade()));

	//testing upgradable()
	prj::house b;

	assert(("Failing to check if the object is upgradable (it shouldn't be possible)", b.upgradable() == true));
	// "== true" is there for better readability
}