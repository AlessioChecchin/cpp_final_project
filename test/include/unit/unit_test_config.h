/**
 * Unit test for configuration class.
 * 
 * @authors Alessio Checchin, Giulio Cattelan
*/

#ifndef UNIT_TEST_CONFIG_H
#define UNIT_TEST_CONFIG_H

#include "../core/test_suite.h"

class unit_test_config: public test_suite
{
public:

	unit_test_config();

	void test_constructor();
	void test_category_config();
	void test_getters();
};

bool test_config_valid();

#endif // UNIT_TEST_CONFIG_H
