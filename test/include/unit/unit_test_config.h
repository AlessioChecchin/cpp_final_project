/**
 * Unit test for configuration class.
 * 
 * @authors Alessio Checchin, Giulio Cattelan
*/

#ifndef UNIT_TEST_CONFIG_H
#define UNIT_TEST_CONFIG_H

#include "core/test_suite.h"
#include "config.h"

class unit_test_config: public test_suite
{
public:

	unit_test_config();

	void test_constructor();
	void test_category_config();
	void test_getters();
};

bool test_config_valid();
bool test_config_valid(unsigned int human_number, unsigned int bot_number);

bool try_get_available_categories(const prj::config& a);

#endif // UNIT_TEST_CONFIG_H
