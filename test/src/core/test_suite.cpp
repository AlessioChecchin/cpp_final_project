/**
 * Implementation of test_suite class.
 * test_suite implementation.
 * 
 * @author Alessio Checchin
*/

#include "core/test_suite.h"

#include <iostream>

test_suite::test_suite(const std::string& test_suite_name):
	test_suite_name_{test_suite_name}
{}

void test_suite::add_test(const test& new_test)
{
	tests_.push_back(new_test);
}

void test_suite::run_test_suite()
{
	std::cout << TEST_SUITE_COLOR << ">> Running test suite [" << test_suite_name_ << "]" << RESET << std::endl;
	
	int i = 1;
	// Running all tests.
	for(test& t: tests_)
	{
		// All the output inside a test will be printed in red. std::flush in necessary to flush the output buffer.
		std::cout << TEST_COLOR << "[" << i << "/" << tests_.size() << "] Running test [" << t.get_name() << "]..." << TEST_FAIL << std::flush;
		t.run_test();
		// The test succeeds if no assertion is thrown.
		std::cout << TEST_SUCCESS << "[ok]" << RESET << std::endl;
		i++;
	}
}