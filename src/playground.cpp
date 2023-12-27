#include "playground.h"

#include <memory>
#include <stdexcept>

#include "player.h"

playground::playground(): field_{}, players_{}
{}

void playground::add_player(std::shared_ptr<player> new_player)
{
	if(new_player->is_playing_)
	{
		throw std::invalid_argument("The player is already assigned to a playground");
	}

	new_player->is_playing_ = true;
	players_[new_player->get_id()] = new_player;
}

std::vector<std::shared_ptr<player>> playground::get_players()
{
	std::vector<std::shared_ptr<player>> result;

	for(auto it = players_.begin(); it != players_.end(); it++)
	{
		result.push_back(it->second);
	}

	return result;
}

void playground::remove_player(std::shared_ptr<player> to_remove)
{
	auto element = find_player(to_remove->get_id());
	
	// Fails silently.
	if(element == players_.end())	
	{
		return;
	}

	element->second->is_playing_ = false;
	players_.erase(element);
}

bool playground::is_playing(std::shared_ptr<player> target)
{
	return find_player(target->get_id()) != players_.end();
}

// Protected methods
std::map<unsigned long int, std::shared_ptr<player>>::iterator
	playground::find_player(unsigned long int id)
{
	return players_.find(id);
}

// Helper functions.
std::ostream& operator<<(std::ostream& os, const playground& play)
{
	return os;
}