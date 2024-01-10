/**
 * Unit test for category class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_CATEGORY_H
#define UNIT_TEST_CATEGORY_H

#include "core/test_suite.h"

class unit_test_category: public test_suite
{
public:

	unit_test_category();

	void test_constructor();
	void test_getters();
};

bool test_category_valid(unsigned int faces);

#endif // UNIT_TEST_CATEGORY_H