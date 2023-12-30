#ifndef TEST_H
#define TEST_H

#include <string>

class test
{
private:
	std::string test_name;
public:
	test(const std::string& test_name);
	virtual void run() = 0;
};

#endif // TEST_H