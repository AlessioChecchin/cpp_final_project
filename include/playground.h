#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <memory>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <array>

#include "player.h"
#include "board.h"

namespace prj
{
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

		/**
		 * Move the player of the specified number of steps.
		 * The player can be moved either forward and backward
		 * @param to_move The player to remove
		 * @param steps Number of steps of the player
		 */
		void move_player(std::shared_ptr<player> to_move, int steps);

	protected:
		/**
		 * Utility function wrapping find.
		*/
		std::map<unsigned long int, std::shared_ptr<player>>::iterator
			find_player(unsigned long int id);

	protected:
		/**
		 * Board of the game 
		 */
		board board_;

		/**
		 * Map that contains all the players in the playground.
		*/
		std::map<unsigned long int, std::shared_ptr<player>> players_;	
	};

	std::ostream& operator<<(std::ostream& os, const playground& play);
}

#endif // PLAYGROUND_H