#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <memory>
#include <set>
#include <vector>
#include <iostream>
#include <array>

#include "player.h"
#include "box.h"

class playground
{
	
protected:
	struct position
	{
		unsigned int address;
		std::unique_ptr<player> player_ref;

		position(unsigned addr, std::unique_ptr<player> new_player);
		bool operator<(const position& p) const;
	};

	std::array<box, 28> field_;
	std::set<position> player_positions_{};
	
public:
	//playground();
	
	void add_player(std::unique_ptr<player> new_player);
	//void remove_player();
	std::vector<std::reference_wrapper<player>> get_players();
	
	//void advance_player();
	
};

std::ostream& operator<<(std::ostream& os, const playground& play);

#endif // PLAYGROUND_H