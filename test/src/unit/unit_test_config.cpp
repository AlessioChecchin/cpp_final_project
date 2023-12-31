#include "unit/unit_test_config.h"

#include <iostream>

unit_test_config::unit_test_config(): test_suite{"u_config"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("getter", std::bind(&unit_test_config::test_getter, this)));
}

void unit_test_config::test_getter()
{
	std::cout << "Gettttttter";
}