/**
 * Unit test for playground class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_PLAYGROUND_H
#define UNIT_TEST_PLAYGROUND_H

#include "core/test_suite.h"

#include "playground.h"
#include "players/player.h"
#include "players/human.h"
#include "players/bot.h"

#include <memory>

class unit_test_playground: public test_suite
{
public:

	unit_test_playground();

	void test_constructor();
	void test_getters();
	void test_methods();
};

bool test_playground_valid();
bool try_get_players(const prj::playground& a);
bool try_get_box_names(const prj::playground& a, unsigned int position);
bool try_get_player_box(const prj::playground& a, std::shared_ptr<prj::player> p);
bool try_add(prj::playground& a, std::shared_ptr<prj::player> p);
bool try_move(prj::playground& a, std::shared_ptr<prj::player> p, int steps);
bool try_remove(prj::playground& a, std::shared_ptr<prj::player> p);

#endif // UNIT_TEST_PLAYGROUND_H