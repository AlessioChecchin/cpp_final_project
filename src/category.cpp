#include "category.h"

namespace prj
{

std::string category::get_name() const
{
	return name_;
};

unsigned int category::get_id() const
{
	return id_;
};

} // prj