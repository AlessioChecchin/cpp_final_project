#include "../../include/unit/unit_test_box.h"
#include "../../../include/box.h"

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
	
}

void unit_test_box::test_getters()
{
	//testing getters
	
}