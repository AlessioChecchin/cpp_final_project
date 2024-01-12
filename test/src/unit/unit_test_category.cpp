#include "../../include/unit/unit_test_category.h"
#include "../../../include/category.h"

#include <iostream>
#include <assert.h>

unit_test_category::unit_test_category(): test_suite{"unit_test_category"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_category::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_category::test_getters, this)));
}

void unit_test_category::test_constructor()
{
	//testing constructor
	prj::category a("Alpha", 1);
	assert(("Failed to create category object a{\"Alpha\", 1}", a.get_name() == "Alpha"));
	assert(("Failed to create category object a{\"Alpha\", 1}", a.get_id() == 0));

	prj::category b("Beta", -1);
	assert(("Failed to create category object b{\"Beta\", 1}", a.get_name() == "Beta"));
	assert(("Failed to create category object b{\"Beta\", 1}", a.get_id() == 0));
}

void unit_test_category::test_getters()
{
	//testing getters
	prj::category a{"Alpha", 0};
	assert(("Failed to create category object b{\"Alpha\", 0}", a.get_name() == "Alpha"));
	assert(("Failed to create category object b{\"Alpha\", 0}", a.get_id() == 0));

	prj::category b{"Beta", 1};
	assert(("Failed to create category object a{\"Beta\", 1}", a.get_name() == "Beta"));
	assert(("Failed to create category object a{\"Beta\", 1}", a.get_id() == 1));
}