#include "unit/unit_test_dice.h"
#include "dice.h"

#include <iostream>
#include <assert.h>
#include <stdexcept>

unit_test_dice::unit_test_dice(): test_suite{"unit_test_dice"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_dice::test_constructor, this)));
	add_test(test("methods", std::bind(&unit_test_dice::test_methods, this)));
}

void unit_test_dice::test_constructor()
{
	//testing constructor
	assert(("Failed to create dice object: prj::dice a(6)", test_dice_valid(6) == true));
	assert(("Failed to create dice object: prj::dice b(1)", test_dice_valid(1) == true));
	assert(("Failed to create dice object: prj::dice d(-1)", test_dice_valid(-1) == true));
	assert(("Failed to create dice object: prj::dice c(0)", test_dice_valid(0) == false));

	//testing move constructor
	prj::dice a{20};
	prj::dice b{4};
	prj::dice c{6};
	prj::dice d{1};
	assert(("Failed to create dice object: prj::dice a(6)", test_dice_valid(a) == true));
	assert(("Failed to create dice object: prj::dice b(1)", test_dice_valid(b) == true));
	assert(("Failed to create dice object: prj::dice d(-1)", test_dice_valid(c) == true));
	assert(("Failed to create dice object: prj::dice c(0)", test_dice_valid(d) == true));

}

void unit_test_dice::test_methods()
{
	//testing roll method
	prj::dice a(6);

	assert(("Failed to roll the dice (it shuldn't be possible)", a.roll()));
	assert(("Failed to roll the dice (it shuldn't be possible)", a.roll()));
	assert(("Failed to roll the dice (it shuldn't be possible)", a.roll()));
	assert(("Failed to roll the dice (it shuldn't be possible)", a.roll()));
	assert(("Failed to roll the dice (it shuldn't be possible)", a.roll()));
	assert(("Failed to roll the dice (it shuldn't be possible)", a.roll()));
}

bool test_dice_valid(unsigned int faces)
{
	try
	{
		prj::dice a(faces);
		return true;
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
}

bool test_dice_valid(prj::dice& d)
{
	try
	{
		prj::dice a(std::move(d));
		return true;
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
}