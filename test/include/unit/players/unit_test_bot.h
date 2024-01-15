/**
 * Unit test for bot player class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_BOT_H
#define UNIT_TEST_BOT_H

#include "core/test_suite.h"
#include "players/bot.h"
#include "players/action.h"
#include "box.h"
#include "config.h"

class unit_test_bot: public test_suite
{
public:

	unit_test_bot();

	void test_constructor();
	void test_methods();
};

bool test_bot_valid(std::shared_ptr<prj::config> configuration);
bool test_bot_valid(unsigned int balance, std::shared_ptr<prj::config> configuration);

bool try_decision(prj::bot& bot, const prj::box* current_box, const std::set<prj::action>& choices);

#endif // UNIT_TEST_BOT_H