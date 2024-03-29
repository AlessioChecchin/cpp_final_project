/**
 * Player implementation
 * 
 * @author Giulio Cattelan
*/

#include "players/player.h"

#include <string>
#include <vector>

namespace prj
{

player::player(): name_{""}, score_{0}, is_playing_{false}, position_{0}, ownerships_{}
{
	// This assignment happens only once.
	static unsigned long int user_id = 1;
	id_ = user_id;
	user_id++;
}

player::player(unsigned int init_balance) : player()
{
	score_ = init_balance;
}

int player::get_score() const
{
	return score_;
}

std::string player::get_name() const 
{
	return name_;
}

unsigned long int player::get_id() const
{
	return id_;
}

void player::set_name(const std::string& name)
{
	name_ = name;
}

unsigned int player::get_pos() const
{
	return position_;
}

std::vector<unsigned int>& player::get_ownerships()
{
	return ownerships_;
}

} // prj