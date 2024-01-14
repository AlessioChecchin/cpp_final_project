/**
 * Unit test for board class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_BOARD_H
#define UNIT_TEST_BOARD_H

#include "core/test_suite.h"

#include "board.h"

class unit_test_board: public test_suite
{
public:

	unit_test_board();

	void test_constructor();
	void test_getters();
	void test_methods();
};

bool test_board_valid(std::shared_ptr<prj::config> configuration);
bool test_get_valid(const prj::board& b, unsigned int position);

#endif // UNIT_TEST_BOARD_H