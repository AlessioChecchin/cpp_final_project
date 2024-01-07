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

}