/**
 * This class represents a test case.
 * 
 * @author Alessio Checchin
*/

#ifndef TEST_H
#define TEST_H

#include <string>
#include <functional>

/**
 * Test case class.
*/
class test
{
public:

	/**
	 * Test case constructor
	 * 
	 * @param test_name The name of the test.
	 * @param proc The test case procedure.
	*/
	test(const std::string& test_name, const std::function<void()>& proc);

	/**
	 * Method used to run the test.
	*/
	void run_test();
	
	/**
	 * Name getter.
	 * @return The test name.
	*/
	std::string get_name() const;

private:
	/**
	 * Test name.
	*/
	std::string test_name_;

	/**
	 * Test procedure.
	*/
	std::function<void()> proc_;
};

#endif // TEST_H