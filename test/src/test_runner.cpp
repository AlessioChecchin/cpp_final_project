#include "test.h"

#include "unit/unit_test_config.h"

#include <iostream>
int main()
{
	unit_test_config utc("U-Config");
	utc.run();
	
	return 0;
}