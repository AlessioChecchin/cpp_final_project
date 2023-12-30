#ifndef UNIT_TEST_CONFIG_H
#define UNIT_TEST_CONFIG_H

#include "test.h"
#include <iostream>

class unit_test_config: public test
{
public:

	unit_test_config(const std::string& test_name): test(test_name)
	{}

	void run()
	{
		std::cout << "Runing test";
	}
};

#endif // UNIT_TEST_CONFIG_H
