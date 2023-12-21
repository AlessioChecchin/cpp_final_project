#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <memory>
#include <vector>

#include "player.h"
#include "box.h"

class playground
{
	
protected:
	box field_[28];
	//std::vector<player_position> player_positions_;
	
	
	class position
	{
		
	};
	
public:
	playground();
	
	void add_player();
	void remove_player();
	void get_players();
	
	void advance_player();
	
};

#endif // PLAYGROUND_H