#include "unit/unit_test_board.h"
#include "../../include/board.h"
#include "../../include/config.h"

#include <iostream>
#include <assert.h>
#include <stdexcept>

unit_test_board::unit_test_board(): test_suite{"unit_test_board"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_board::test_constructor, this)));
	add_test(test("methods", std::bind(&unit_test_board::test_methods, this)));
	add_test(test("operators", std::bind(&unit_test_board::test_operators, this)));
}

void unit_test_board::test_constructor()
{
	//testing constructor
	assert(("Failed to create board object", test_board_valid()));
}

void unit_test_board::test_methods()
{
	//testing is_angular()
	//N.B.: FIELD_SIZE = 28, angular boxes are: 0, 7, 14, 21
	prj::board a(std::shared_ptr<prj::config>(new prj::config()));
	
	// "== true" is there for better readability
	assert(("Failing to determine that box 0 is angular", a.is_angular(0) == true));
	assert(("Failing to determine that box 7 is angular", a.is_angular(7) == true));
	assert(("Failing to determine that box 14 is angular", a.is_angular(14) == true));
	assert(("Failing to determine that box 21 is angular", a.is_angular(21) == true));

	// "== false" is there instead of "!" for better readability
	assert(("Failing to determine that box 1 is not angular", a.is_angular(1) == false));
	assert(("Failing to determine that box 4 is not angular", a.is_angular(4) == false));
	assert(("Failing to determine that box 17 is not angular", a.is_angular(17) == false));
	assert(("Failing to determine that box -1 is not angular", a.is_angular(-1) == false));

	
}

void unit_test_board::test_operators()
{
	//testing operator<<
}

bool test_board_valid()
{
	try
	{
		prj::board a(std::shared_ptr<prj::config>(new prj::config()));
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}