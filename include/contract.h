/**
 * Contract class.
 * 
 * @author Alessio Checchin.
*/

#ifndef CONTRACT_H
#define CONTRACT_H

#include <memory>

#include "building/building.h"
#include "players/player.h"


namespace prj
{

class player;

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

	/**
	 * Returns the owner associated with the contract.
	 * If the contract has no owner, null is returned.
	 * @return The owner if is set, null otherwise.
	*/
	std::shared_ptr<player> get_owner() const;

	/**
	 * Sets the owner of the contract.
	 * To set no owner, just pass a null pointer.
	 * @param owner The owner of the contract. If the contract has not owner set it to null.
	*/
	void set_owner(std::shared_ptr<player> owner);

	/**
	 * Returns a NON-OWNING pointer to the building associated with the contract.
	 * The lifetime of this pointer is automatically handled, you MUST NOT delete it.
	 * @return A pointer to the building associated with the contract.
	*/
	building* get_building();

	/**
	 * Returns a NON-OWNING pointer to the building associated with the contract.
	 * The lifetime of this pointer is automatically handled, you MUST NOT delete it.
	 * @return A pointer to the building associated with the contract.
	*/
	const building* get_building() const;

	void set_owner(std::shared_ptr<player> new_player);

	/**
	 * Sets a new building.
	 * @param new_building The new building.
	*/
	void set_building(std::unique_ptr<building> new_building);
	
private:

	/**
	 * Contract building.
	*/
	std::unique_ptr<building> building_;

	/**
	 * Contract owner. Might be null.
	*/
	std::shared_ptr<player> owner_;
};

} // prj

#endif // CONTRACT_H