#include "unit/unit_test_contract.h"
#include "contract.h"

#include <iostream>
#include <assert.h>

unit_test_contract::unit_test_contract(): test_suite{"unit_test_contract"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_contract::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_contract::test_getters, this)));
}

void unit_test_contract::test_constructor()
{
	//testing default constructor
	
}

void unit_test_contract::test_getters()
{
	//testing getters
	
}