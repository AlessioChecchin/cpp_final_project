/**
 * Implementation of hotel class unit test.
 * unit_test_hotel implementation.
 * 
 * @author Giulio Cattelan
*/

#include "unit/building/unit_test_hotel.h"
#include "building/hotel.h"

#include <iostream>
#include <assert.h>
#include <stdexcept>

unit_test_hotel::unit_test_hotel(): test_suite{"unit_test_hotel"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_hotel::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_hotel::test_getters, this)));
	add_test(test("methods", std::bind(&unit_test_hotel::test_methods, this)));
}

void unit_test_hotel::test_constructor()
{
	//testing default constructor
	prj::hotel a;

	assert(("Failing to create hotel object a:", a.get_name() == "hotel"));
	assert(("Failing to create hotel object a:", a.get_id() == 2));
}

void unit_test_hotel::test_getters()
{
	//testing getters
	prj::hotel a;

	assert(("Failing to create hotel object a:", a.get_name() == "hotel"));
	assert(("Failing to create hotel object a:", a.get_id() == 2));
}

void unit_test_hotel::test_methods()
{
	//testing upgrade()
	prj::hotel a;

	assert(("Failing to not upgrade the object (it shouldn't be possible)", try_upgrade(a)));

	//testing upgradable()
	prj::hotel b;

	assert(("Failing to check if the object is upgradable (it shouldn't be possible)", b.upgradable() == false));
	// "== false" is there instead of "!" for better readability
}

bool try_upgrade(const prj::hotel& a)
{
	try
	{
		a.upgrade();
		return false;
	}
	catch(const std::invalid_argument& e)
	{
		return true;
	}
}