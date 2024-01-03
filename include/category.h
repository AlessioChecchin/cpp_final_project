#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

namespace prj
{

class category
{
public:

	std::string get_name() const
	{
		return name_;
	};

	unsigned int get_id() const
	{
		return id_;
	};

private:
	std::string name_;
	unsigned int id_;
};

} // prj

#endif // CATEGORY_H