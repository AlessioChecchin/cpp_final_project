#include "contract.h"
#include "building/terrain.h"

namespace prj
{

contract::contract(): owner_{nullptr}, building_{std::unique_ptr<building>(new terrain())}
{}

std::shared_ptr<player> contract::get_owner() const
{
	return owner_;
}

building* contract::get_building()
{
	return building_.get();
};

const building* contract::get_building() const
{
	return building_.get();
};

void contract::set_owner(std::shared_ptr<player> new_player)
{
	owner_ = new_player;
}

void contract::set_building(std::unique_ptr<building> new_building)
{
	// Replace the old building with the new one.
	// Old building is auomtatically deleted.
	building_ = std::move(new_building);
}

}