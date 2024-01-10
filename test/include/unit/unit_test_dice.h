/**
 * Unit test for dice class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_DICE_H
#define UNIT_TEST_DICE_H

#include "core/test_suite.h"

class unit_test_dice: public test_suite
{
public:

	unit_test_dice();

	void test_constructor();
	void test_methods();
};

bool test_dice_valid(unsigned int faces);

#endif // UNIT_TEST_DICE_H