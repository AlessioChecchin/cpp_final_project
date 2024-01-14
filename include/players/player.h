/**
 * Player class.
 * 
 * @author Alessio Checchin
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>
#include <vector>

#include "box.h"
#include "players/action.h"

// Forward declaration.
class box;

namespace prj
{

class player
{
public:
	/**
	 * Copy disabled.
	*/
	player(const player& my_player) = delete;

	/**
	 * Copy disabled.
	*/
	player& operator=(const player& my_player) = delete;

	/**
	 * Name getter.
	 * @return The player's name.
	*/
	std::string get_name() const;

	/**
	 * Name setter.
	 * @param name The player's new name.
	*/
	void set_name(const std::string& name);

	/**
	 * Id getter.
	 * @return The player's id.
	*/
	unsigned long int get_id() const;

	/**
	 * Position getter 
	 * @return The player position on the board
	 */
	unsigned int get_pos() const;

	/**
	 * Score getter
	 * @return The amount of money the player has
	 */
	int get_score() const;

	/**
	 * Decision taken by the player
	 * @param current_box The box the player is in.
	 * @param choices A set of possible choices.
	 * @return One of the choices.
	 */
	virtual action decision(const box* current_box, const std::set<action>& choices) = 0;

	/**
	 * We decided to use friend to enforce encapsulation and allow 
	 * only read methods for certain fields. We want playground to handle
	 * the logic of score assignment ans positioning of the players. At the same
	 * time we want that theese informations are readable but not modifiable from outside
	 * playground. The trade-off is creating a tight-coupled class to enforce encapsulation.
	*/
	friend class playground;

private:

	/**
	 * Player name.
	*/
	std::string name_{};

	/**
	 * Player score.
	*/
	int score_{};

	/**
	 * Is playing in a generic playground.
	*/
	bool is_playing_{};

	/**
	 * Player id. Is unique.
	*/
	unsigned long int id_{};

	/**
	 * Player position in a playground.
	*/
	unsigned int position_{};

	/**
	 * Indexes of the boxes that the player owns.
	*/
	std::vector<unsigned int> ownerships_{};

protected:

	/**
	 * Default constructor.
	 * This constructor MUST be called by any subclass in order to correctly initialize the player id.
	*/
	player();

	/**
	 * Create player with initial balance.
	 * @param init_balance Initial balance of the player.
	 */
	player(unsigned int init_balance);
};

} // prj

#endif // PLAYER_H