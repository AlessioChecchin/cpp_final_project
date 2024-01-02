#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class playground;

namespace prj
{
	class player
	{

	private:
		std::string name_{};
		int score_{};
		bool is_playing_{};
		unsigned long int id_{};
		unsigned int position_;

	public:

		/**
		 * Default constructor.
		*/
		player();

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
		unsigned int get_pos();

		/**
		 * We decided to use friend to enforce encapsulation and allow 
		 * only read methods for certain fields. We want playground to handle
		 * the logic of score assignment ans positioning of the players. At the same
		 * time we want that theese informations are readable but not modifiable from outside
		 * playground. The trade-off is creating a tight-coupled class to enforce encapsulation.
		*/
		friend class playground;	
	};
}

#endif // PLAYER_H