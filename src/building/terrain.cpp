/**
 * Terrain building implementation.
 * 
 * @author Giulio Cattelan
*/

#include "building/terrain.h"
#include "building/house.h"
#include "building/building.h"

#include <memory>
#include <stdexcept>

namespace prj
{

terrain::terrain(): building("terrain", 0)
{}	

std::unique_ptr<building> terrain::upgrade() const
{
	return std::unique_ptr<building>(new house());
}

bool terrain::upgradable() const
{
	return true;
}

} // prj