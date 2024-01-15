/**
 * Unit test for logger class.
 * 
 * @authors  Giulio Cattelan
*/

#ifndef UNIT_TEST_LOGGER_H
#define UNIT_TEST_LOGGER_H

#include "core/test_suite.h"

class unit_test_logger: public test_suite
{
public:

	unit_test_logger();

	void test_methods();
};

#endif // UNIT_TEST_LOGGER_H