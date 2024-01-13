#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>

#include "box.h"
#include "players/action.h"

class box;
namespace prj
{
	class player
	{

	public:
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
		unsigned int get_score() const;

		/**
		 * Decision of the player 
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
		std::string name_{};
		int score_{};
		bool is_playing_{};
		unsigned long int id_{};
		unsigned int position_;

	protected:
		/**
		 * Default constructor
		*/
		player();

		/**
		 * Create player with initial balance
		 */
		player(unsigned int init_balance);

	};
}

#endif // PLAYER_H