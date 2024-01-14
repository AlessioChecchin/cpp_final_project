#include "unit/unit_test_board.h"
#include "board.h"
#include "config.h"


#include <iostream>
#include <assert.h>
#include <stdexcept>

unit_test_board::unit_test_board(): test_suite{"unit_test_board"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_board::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_board::test_getters, this)));
	add_test(test("methods", std::bind(&unit_test_board::test_methods, this)));
}

void unit_test_board::test_constructor()
{
	//testing constructor
	assert(("Failed to create board object", test_board_valid(std::shared_ptr<prj::config>(new prj::config())) == true));

	assert(("Failed not to create board object", test_board_valid(nullptr) == false));
}

void unit_test_board::test_getters()
{
	//testing getters
	prj::board a{std::unique_ptr<prj::config>(new prj::config())};

	assert(("Failing to get box 1 from board oobject a", test_get_valid(a, 1) == true));
	assert(("Failing to get box 0 from board oobject a", test_get_valid(a, 0) == true));
	assert(("Failing to get box 12 from board oobject a", test_get_valid(a, 12) == true));
	assert(("Failing to get box 2 from board oobject a", test_get_valid(a, 2) == true));
	
	assert(("Failing to get box -1 from board oobject a", test_get_valid(a, -1) == false));
	assert(("Failing to get box 35 from board oobject a", test_get_valid(a, 35) == false));
}

void unit_test_board::test_methods()
{
	//testing is_angular()
	//N.B.: FIELD_SIZE = 28, angular boxes are: 0, 7, 14, 21
	prj::board a{std::shared_ptr<prj::config>(new prj::config())};
	
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

bool test_board_valid(std::shared_ptr<prj::config> configuration)
{
	try
	{
		prj::board a(configuration);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool test_get_valid(const prj::board& b, unsigned int position)
{
	try
	{
		b.get_box(position);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}