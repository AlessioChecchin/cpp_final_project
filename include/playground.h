#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <memory>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <array>

#include "player.h"
#include "box.h"

class playground
{	
public:
	playground();
	
	/**
	 * Adds a player to the playground.
	 * @param new_player The player to add.
	 * 
	*/
	void add_player(std::shared_ptr<player> new_player);

	/**
	 * Removes a player from the playground.
	 * @param to_remove The player to remove.
	*/
	void remove_player(std::shared_ptr<player> to_remove);

	/**
	 * Returns a vector containing the players in the playground.
	 * @return A vector of shared pointers to players.
	*/
	std::vector<std::shared_ptr<player>> get_players();

	/**
	 * Tests if a player is present in the playground.
	 * @return true if the player is present, false otherwise.
	*/
	bool is_playing(std::shared_ptr<player> to_remove);

protected:
	/**
	 * Utility function wrapping find.
	*/
	std::map<unsigned long int, std::shared_ptr<player>>::iterator
		find_player(unsigned long int id);

protected:

	/**
	 * Size of the field.
	*/
	const static int FIELD_SIZE = 28;

	/**
	 * Array representing the field.
	*/
	std::array<box, FIELD_SIZE> field_;

	/**
	 * Map that contains all the players in the playground.
	*/
	std::map<unsigned long int, std::shared_ptr<player>> players_;	
};

std::ostream& operator<<(std::ostream& os, const playground& play);

#endif // PLAYGROUND_H