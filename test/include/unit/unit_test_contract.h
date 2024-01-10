/**
 * Unit test for contract class.
 * 
 * @author Giulio Cattelan
*/

#ifndef UNIT_TEST_CONTRACT_H
#define UNIT_TEST_CONTRACT_H

#include "core/test_suite.h"

class unit_test_contract: public test_suite
{
public:

	unit_test_contract();

	void test_constructor();
	void test_getters();
};

#endif // UNIT_TEST_CONTRACT_H