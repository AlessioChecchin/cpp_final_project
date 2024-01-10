/**
 * Unit test for human player class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_HUMAN_H
#define UNIT_TEST_HUMAN_H

#include "../../core/test_suite.h"

class unit_test_human: public test_suite
{
public:

	unit_test_human();

	void test_constructor();
	void test_getters();
	void test_setters();
	void test_methods();
};

#endif // UNIT_TEST_HUMAN_H