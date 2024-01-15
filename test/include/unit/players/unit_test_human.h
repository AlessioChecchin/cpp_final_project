/**
 * Unit test for human player class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_HUMAN_H
#define UNIT_TEST_HUMAN_H

#include "core/test_suite.h"
#include "players/human.h"
#include "players/action.h"
#include "box.h"

#include <algorithm>

class unit_test_human: public test_suite
{
public:

	unit_test_human();

	void test_constructor();
	void test_methods();
};

bool test_human_valid();
bool test_human_valid(unsigned int balance);

bool try_decision(prj::human& human, const prj::box* current_box, const std::set<prj::action>& choices);

#endif // UNIT_TEST_HUMAN_H