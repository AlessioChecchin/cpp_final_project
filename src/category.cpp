#include "category.h"

namespace prj
{

category::category(const std::string& name, unsigned int id): name_{name}, id_{id}
{}

std::string category::get_name() const
{
	return name_;
};

unsigned int category::get_id() const
{
	return id_;
};

} // prj