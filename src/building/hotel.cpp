/**
 * Hotel building implementation.
 * 
 * @author Alessio Checchin
*/

#include "building/hotel.h"
#include "building/building.h"

#include <memory>
#include <stdexcept>

namespace prj
{

hotel::hotel(): building("hotel", 2)
{}

std::unique_ptr<building> hotel::upgrade() const
{
	throw std::invalid_argument("Cannot upgrade a non-upgradable building");
}

bool hotel::upgradable() const
{
	return false;
}

} // prj