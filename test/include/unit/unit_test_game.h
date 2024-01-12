/**
 * Unit test for game class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_GAME_H
#define UNIT_TEST_GAME_H

#include "../core/test_suite.h"

#include <memory>

class unit_test_game: public test_suite
{
public:

	unit_test_game();

	void test_constructor();
};

bool test_game_valid();

#endif // UNIT_TEST_GAME_H