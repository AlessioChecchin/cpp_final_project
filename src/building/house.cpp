/**
 * House building.
 * 
 * @author Alessio Checchin
*/

#include "building/house.h"
#include "building/hotel.h"
#include "building/building.h"

#include <memory>
#include <stdexcept>

namespace prj
{

house::house(): building("house", 1)
{}	

std::unique_ptr<building> house::upgrade() const
{
	return std::unique_ptr<building>(new hotel());
}

bool house::upgradable() const
{
	return true;
}

} // prj