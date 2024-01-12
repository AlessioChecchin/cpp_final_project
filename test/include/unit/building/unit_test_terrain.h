/**
 * Unit test for terrain building class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_TERRAIN_H
#define UNIT_TEST_TERRAIN_H

#include "../../core/test_suite.h"

class unit_test_terrain: public test_suite
{
public:

	unit_test_terrain();

	void test_constructor();
	void test_getters();
	void test_methods();
};

#endif // UNIT_TEST_TERRAIN_H