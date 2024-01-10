/**
 * Unit test for hotel building class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_HOTEL_H
#define UNIT_TEST_HOTEL_H

#include "../../core/test_suite.h"
#include "../../../../include/building/hotel.h"

#include <memory>

class unit_test_hotel: public test_suite
{
public:

	unit_test_hotel();

	void test_constructor();
	void test_getters();
	void test_methods();
};

bool try_upgrade(const prj::hotel& a);

#endif // UNIT_TEST_HOTEL_H