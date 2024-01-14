#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <memory>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <array>
#include <string>


#include "players/player.h"
#include "board.h"
#include "config.h"

namespace prj
{
class playground
{	
public:

	playground(std::shared_ptr<config> configuration);

    /**
	 * Copy disabled
	*/
	playground(const playground& b) = delete;

	/**
	 * Copy disabled
	*/
	playground& operator=(const playground& b) = delete;

	/**
	 * Adds a player to the playground.
	 * @param my_player The player to add.
	*/
	virtual void add_player(std::shared_ptr<player> my_player);

	/**
	 * Getter for the box name 
	 * @param pos Position index
	 * @return Box name (row-column)
	 */
	virtual std::string get_box_name(unsigned int pos) const;

	/**
	 * Obtain the player that has to play the current round
	 * @return Player that has to play
	 */
	virtual std::shared_ptr<player> next_player();

	/**
	 * Returns if there is a next player.
	 * @returns If there is a next player.
	*/
	virtual bool has_next_player() const;

	/**
	 * Getter for number of players playing
	 * @return Number of players in the game
	 */
	virtual unsigned int number_players() const;

	/**
	 * Removes a player from the playground.
	 * @param my_player The player to remove.
	*/
	virtual void remove_player(std::shared_ptr<player> my_player);

	/**
	 * Returns a vector containing the players in the playground.
	 * @return A vector of shared pointers to players.
	*/
	virtual std::vector<std::shared_ptr<player>> get_players();

	/**
	 * Returns a vector containing the players in the playground.
	 * @return A vector of shared pointers to players.
	*/
	virtual std::vector<std::shared_ptr<const player>> get_players() const;

	/**
	 * Tests if a player is present in the playground.
	 * @param my_player The player to check.
	 * @return true if the player is present, false otherwise.
	*/
	virtual bool is_playing(std::shared_ptr<player> my_player) const;

	/**
	 * Move the player of the specified number of steps.
	 * The player can be moved either forward and backward
	 * @param my_player The player to move
	 * @param steps Number of steps of the player
	 */
	virtual void move_player(std::shared_ptr<player> my_player, int steps);

	/**
	 * Performs the action that should occur when a player steps on a new box.
	 * @param my_player The player that is performing the action.
	 * @return The performed action.
	*/
	virtual action perform_action(std::shared_ptr<player> my_player);

	/**
	 * Player box getter.
	 * @param my_player The player on the box.
	 * @return The box on which the player is.
	*/
	const box* get_player_box(std::shared_ptr<player> my_player) const;

protected:

	/**
	 * Returns a label containing the main text of a label.
	 * @param position The position of the current cell.
	 * @return The formatted text.
	*/
	virtual std::string format_text(unsigned int position) const;

	/**
	 * Returns a label contaning the players that are int the current position.
	 * @param map A multimap with key = position and value = player.
	 * @param position The position of the current cell.
	 * @return The formatted text.
	*/
	virtual std::string format_label_players(const std::multimap<unsigned int, std::shared_ptr<const player>>& map, unsigned int position) const;

	/**
	 * Returns a complete label, that combines text and players.
	 * @param map A multimap with key = position and value = player.
	 * @param position The position of the current cell.
	 * @param cell_width The desired width of the cell.
	 * @return The formatted text. If cell_width = 0 then returns text + player label. If is != 0
	 * returns a centered label containing text and player label.
	*/
	virtual std::string format_label(const std::multimap<unsigned int, std::shared_ptr<const player>>& map, unsigned int position, unsigned int cell_width = 0) const;

	/**
	 * Resizes and centers a label.
	 * @param original The original string.
	 * @param desired_size The desired size of the label.
	 * @param delimiter An optional delimiter.
	 * @return The adapted string. If the string is bigger than desired_size, then 
	 * the string is not trimmed, but is returned as-is concatenated with separators.
	*/
	virtual std::string adapt_label_size(const std::string& original, unsigned int desired_size, char delimiter = '|') const;

	/**
	 * Board of the game 
	 */
	board board_;

	/**
	 * Map that contains all the players in the playground.
	*/
	std::vector<std::shared_ptr<player>> players_{};	
	/**
	 * Index of the player that has to play the current round
	 */
	unsigned int player_index{};
	
	/**
	 * Configuration
	*/
	std::shared_ptr<config> configuration_{};

	/**
	 * Operator overload.
	*/
    friend std::ostream& operator<<(std::ostream& os, const playground& play);
};

}

#endif // PLAYGROUND_H