#include "contract.h"

namespace prj
{

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