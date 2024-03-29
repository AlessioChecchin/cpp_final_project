/**
 * Contract class.
 * 
 * @author Alessio Checchin.
*/

#include "contract.h"

#include <memory>

#include "building/terrain.h"

namespace prj
{

contract::contract(): owner_{nullptr}, building_{std::unique_ptr<building>(new terrain())}
{}

std::shared_ptr<player> contract::get_owner() const
{
	return owner_;
}

void contract::set_owner(std::shared_ptr<player> owner)
{
	// May be null.
	owner_ = owner;
}

building* contract::get_building()
{
	return building_.get();
};

const building* contract::get_building() const
{
	return building_.get();
};

void contract::set_building(std::unique_ptr<building> new_building)
{
	// Replace the old building with the new one.
	// Old building is auomtatically deleted.
	building_ = std::move(new_building);
}

} // prj