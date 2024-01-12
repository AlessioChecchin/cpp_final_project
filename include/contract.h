#ifndef CONTRACT_H
#define CONTRACT_H

#include <memory>

#include "building/building.h"
#include "players/player.h"

namespace prj
{

class contract
{
public:

	contract();
	/**
	 * A contract is unique and contains non copiable objects.
	*/
	contract(const contract& c) = delete;

	/**
	 * A contract is unique and contains non copiable objects.
	*/
	contract& operator=(const contract& c) = delete;

	std::shared_ptr<player> get_owner() const;

	building* get_building();

	const building* get_building() const;

	void set_building(std::unique_ptr<building> new_building);
	
private:
	std::unique_ptr<building> building_;
	std::shared_ptr<player> owner_;
};

} // prj

#endif // CONTRACT_H