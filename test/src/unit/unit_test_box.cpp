/**
 * Implementation of box class unit test.
 * unit_test_box implementation.
 * 
 * @author Giulio Cattelan
*/

#include "unit/unit_test_box.h"
#include "box.h"
#include "category.h"

#include <iostream>
#include <assert.h>

unit_test_box::unit_test_box(): test_suite{"unit_test_box"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_box::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_box::test_getters, this)));
}

void unit_test_box::test_constructor()
{
	//testing constructor
	prj::category a{"Alpha", 1};
	prj::box b(a);

	assert(("Failing to create category a in box object b", b.get_category().get_name() == "Alpha"));
	assert(("Failing to create category a in box object b", b.get_category().get_id() == 1));
	assert(("Failing to create default contract in box object b", b.get_contract()));
	//cannot test the default contract because it is an unique_ptr
}

void unit_test_box::test_getters()
{
	//testing getters
	prj::category a{"Alpha", 1};
	prj::box b{a};

	assert(("Failing to create category a in box object b", b.get_category().get_name() == "Alpha"));
	assert(("Failing to create category a in box object b", b.get_category().get_id() == 1));
	assert(("Failing to create default contract in box object b", b.get_contract()));
	//cannot test the default contract because it is an unique_ptr
}