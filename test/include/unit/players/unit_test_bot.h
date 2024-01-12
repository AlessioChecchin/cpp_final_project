/**
 * Unit test for bot player class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_BOT_HUMAN_H
#define UNIT_BOT_HUMAN_H

#include "../../core/test_suite.h"

class unit_test_bot: public test_suite
{
public:

	unit_test_bot();

	void test_constructor();
	void test_getters();
	void test_setters();
	void test_methods();
};

#endif // UNIT_BOT_HUMAN_H