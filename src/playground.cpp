#include "playground.h"

#include <memory>

#include "player.h"

playground::position::position(unsigned addr, std::unique_ptr<player> new_player):
	address{addr}, player_ref{std::move(new_player)}
{}


bool playground::position::operator<(const position& p) const
{
	return player_ref < p.player_ref;
}

void playground::add_player(std::unique_ptr<player> new_player)
{
	player_positions_.emplace(position{0, std::move(new_player)});
}

std::vector<std::reference_wrapper<player>> playground::get_players()
{
	std::vector<std::reference_wrapper<player>> result;

	for(auto it = player_positions_.begin(); it != player_positions_.end(); it++)
	{
		result.push_back(*(it->player_ref.get()));
	}

	return result;
}

// Helper functions.

std::ostream& operator<<(std::ostream& os, const playground& play)
{
	return os;
}