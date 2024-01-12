/**
 * Unit test for box class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_BOX_H
#define UNIT_TEST_BOX_H

#include "../core/test_suite.h"

class unit_test_box: public test_suite
{
public:

	unit_test_box();

	void test_constructor();
	void test_getters();
};

#endif // UNIT_TEST_BOX_H