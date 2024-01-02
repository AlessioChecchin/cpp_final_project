#include "player.h"

#include <string>

namespace prj
{
	player::player(): name_{""}, is_playing_{false}, position_{0}
	{
		// This assignment happens only once.
		static unsigned long int user_id = 0;
		id_ = user_id;
		user_id++;
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

	unsigned int player::get_pos()
	{
		return position_;
	}
}