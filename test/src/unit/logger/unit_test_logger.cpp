#include "unit/logger/unit_test_logger.h"
#include "logger/logger.h"

unit_test_logger::unit_test_logger(): test_suite{"unit_test_logger"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("methods", std::bind(&unit_test_logger::test_methods, this)));
}

void unit_test_logger::test_methods()
{
	//prj::logger& l = get_logger();
}