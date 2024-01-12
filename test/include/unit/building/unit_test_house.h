/**
 * Unit test for house building class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_HOUSE_H
#define UNIT_TEST_HOUSE_H

#include "../../core/test_suite.h"

class unit_test_house: public test_suite
{
public:

	unit_test_house();

	void test_constructor();
	void test_getters();
	void test_methods();
};

#endif // UNIT_TEST_HOUSE_H