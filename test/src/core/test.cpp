/**
 * Implementation of test class.
 * test implementation.
 * 
 * @author Alessio Checchin
*/

#include "core/test.h"

#include "config.h"

test::test(const std::string& test_name, const std::function<void()>& proc):
	test_name_{test_name},
	proc_{proc}
{}

void test::run_test()
{
	// Invokes the procedure.
	proc_();
}

std::string test::get_name() const
{
	return test_name_;
}