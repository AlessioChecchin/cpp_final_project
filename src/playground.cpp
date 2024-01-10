#include "playground.h"

#include <memory>
#include <stdexcept>
#include <cmath>
#include <algorithm>

#include "players/player.h"
#include "board.h"
#include "config.h"

namespace prj
{
	playground::playground(std::shared_ptr<config> configuration): board_{configuration}, players_{}, player_index{0}
	{}

	std::shared_ptr<player> playground::next_player()
	{
		return players_[player_index++];
	}

	void playground::add_player(std::shared_ptr<player> new_player)
	{
		if(new_player->is_playing_)
		{
			throw std::invalid_argument("The player is already assigned to a playground");
		}

		new_player->is_playing_ = true;
		players_.push_back(new_player);
	}

	std::vector<std::shared_ptr<player>> playground::get_players()
	{
		return players_;
	}

	void playground::remove_player(std::shared_ptr<player> to_remove)
	{
		auto element = find_player(to_remove->get_id());

		// Fails silently.
		if(element == players_.end())	
		{
			return;
		}

		(*element)->is_playing_ = false; 
		players_.erase(element);
	}

	bool playground::is_playing(std::shared_ptr<player> target)
	{
		return find_player(target->get_id()) != players_.end();
	}

	void playground::move_player(std::shared_ptr<player> to_move, int steps)
	{
        bool moving_forward = true;

		// Get number of laps when adding steps 
        int laps = static_cast<int>(std::abs(steps) / board_.FIELD_SIZE);
        
		// Cast 'steps' in range [0, FIELD_SIZE[
        if(steps < 0)
        {
            moving_forward = false;
            steps += board_.FIELD_SIZE + board_.FIELD_SIZE * laps;
        }
        else
        {
            steps -= board_.FIELD_SIZE * laps;
        }
        
		// Add steps and check if it's over FIELD_SIZE
        to_move->position_ += steps;
        if(to_move->position_ >= board_.FIELD_SIZE)
        {
            to_move->position_ -= board_.FIELD_SIZE;
            laps++;
        }

		// Add money to the player
		if(moving_forward)
			to_move->score_ += 9999999*laps;

	}


	// Protected methods

	std::vector<std::shared_ptr<player>>::iterator playground::find_player(unsigned long int id)
	{
		return std::find_if(players_.begin(), players_.end(), [id](std::shared_ptr<player> p)
		{
			return p->get_id() == id;
		});
	}

	// Helper functions.
	std::ostream& operator<<(std::ostream& os, const playground& play)
	{
		return os;
	}
}