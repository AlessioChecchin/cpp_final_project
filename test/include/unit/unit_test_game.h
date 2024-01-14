/**
 * Unit test for game class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_GAME_H
#define UNIT_TEST_GAME_H

#include "core/test_suite.h"
#include "config.h"
#include "game.h"

#include <memory>

class unit_test_game: public test_suite
{
public:

	unit_test_game();

	void test_constructor();
	void test_methods();
};

bool test_game_valid(std::shared_ptr<prj::config> configuration);
bool try_run(prj::game& game);

#endif // UNIT_TEST_GAME_H