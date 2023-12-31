/**
 * Unit test for configuration file.
 * 
 * @author Alessio Checchin
*/

#ifndef UNIT_TEST_CONFIG_H
#define UNIT_TEST_CONFIG_H

#include "core/test_suite.h"

class unit_test_config: public test_suite
{
public:

	unit_test_config();

	void test_getter();
};

#endif // UNIT_TEST_CONFIG_H
