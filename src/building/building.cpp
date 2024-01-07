/**
 * Building implementation.
 * 
 * @author Alessio Checchin
*/

#include "building/building.h"

#include <string>

namespace prj
{

building::building(const std::string& name, unsigned int id): name_{name}, id_{id}
{}

std::string building::get_name() const
{
	return name_;
}

unsigned int building::get_id() const
{
	return id_;
}

} // prj
