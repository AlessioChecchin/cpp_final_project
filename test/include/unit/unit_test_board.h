/**
 * Unit test for board class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_BOARD_H
#define UNIT_TEST_BOARD_H

#include "../core/test_suite.h"

class unit_test_board: public test_suite
{
public:

	unit_test_board();

	void test_constructor();
	void test_methods();
	void test_operators();
};

bool test_board_valid();

#endif // UNIT_TEST_BOARD_H