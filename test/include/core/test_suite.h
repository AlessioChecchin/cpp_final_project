/**
 * This class contains and runs a group of test.
 * Each group of tests is associated to a child of this class.
 * It provides a case for unit tests and integration tests.
 * 
 * @author Alessio Checchin
*/

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <string>
#include <vector>

#include "test.h"
#include "test_config.h"

/**
 * Test suite class. Allows to automatically run a group of tests.
*/
class test_suite
{
public:
	/**
	 * Test suite constructor.
	 * @param test_suite_name The name of the test suite.
	*/
	test_suite(const std::string& test_suite_name);

	/**
	 * Method used to run all contained tests.
	*/
	void run_test_suite();

	/**
	 * Method used to bind a new test case.
	*/
	void add_test(const test& new_test);

private:

	/**
	 * The name of the test suite.
	*/
	std::string test_suite_name_;

	/**
	 * Contained tests.
	*/
	std::vector<test> tests_;
};

// Here are defined the ansi codes used when prompting during tests.
#ifndef DISABLE_ANSI_COLOR
	#define TEST_SUITE_COLOR "\033[1;36m"
	#define TEST_COLOR ""
	#define TEST_SUCCESS "\033[1;32m"
	#define RESET "\033[0m"
#else
	#define TEST_SUITE_COLOR ""
	#define TEST_COLOR ""
	#define TEST_SUCCESS ""
	#define RESET ""
#endif

#endif // TEST_SUITE_H