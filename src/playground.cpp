#include "playground.h"

#include <memory>
#include <stdexcept>
#include <iomanip>
#include <cmath>

#include "players/player.h"
#include "board.h"
#include "config.h"

namespace prj
{
	playground::playground(std::shared_ptr<config> configuration): board_{configuration}, players_{}
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
	std::map<unsigned long int, std::shared_ptr<player>>::iterator
		playground::find_player(unsigned long int id)
	{
		return players_.find(id);
	}

	// Helper functions.
	std::ostream& operator<<(std::ostream& os, const playground& play)
	{
		for(int i = 0; i < 8; i++)
		{
			const box* current_box = play.board_.get_box(i);

			std::string name;

			if(current_box)
			{
				name = current_box->get_category().get_name();
			}
			else
			{
				name = "null";
			}
			
			if(i % 3)
			{
				name = "|X^X|";
			}
			else
			{
				name = "| S |";
			}
			
			os << name << " ";
		}

		os << std::endl;

		for(int i = 0; i < 10; i++)
		{
			os << std::setw(5 * 8 + 7 - 5) << std::left << "|LFT|" << std::right << "|RHT|" << std::endl;
		}

		/*for(unsigned int i = 0; i < play.board_.FIELD_SIZE; i++)
		{
			const box* current_box = play.board_.get_box(i);

			std::string name;

			if(current_box)
			{
				name = current_box->get_category().get_name();
			}
			else
			{
				name = "null";
			}
			
			
			std::cout << std::setw(4) << "S" << std::left << std::endl;
			

		}*/
		return os;
	}
}