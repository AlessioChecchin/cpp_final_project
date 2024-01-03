#ifndef CONTRACT_H
#define CONTRACT_H

#include <memory>

#include "building.h"
#include "player.h"

namespace prj
{

class contract
{
public:
	contract(const contract& c) = delete;
	contract& operator=(const contract& c) = delete;

	std::shared_ptr<player> get_owner() const
	{
		return owner_;
	}

	building* get_building()
	{
		return building_.get();
	};

	const building* get_building() const
	{
		return building_.get();
	};
	
private:
	std::unique_ptr<building> building_;
	std::shared_ptr<player> owner_;
};

} // prj

#endif // CONTRACT_H