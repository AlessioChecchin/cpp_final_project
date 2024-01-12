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
	playground::playground(std::shared_ptr<config> configuration): board_{configuration}, players_{}, configuration_{configuration}
	{
		if(!configuration)
		{
			throw std::invalid_argument("Config can't be null");
		}
	}

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

	std::vector<std::shared_ptr<const player>> playground::get_players() const
	{
		std::vector<std::shared_ptr<const player>> result;

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

	bool playground::is_playing(std::shared_ptr<player> target) const
	{
		return players_.find(target->get_id()) != players_.end();
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
	std::string _calc_name
	(
		unsigned int position,
		const playground& p,
		const box* current_box,
		const std::shared_ptr<config>& conf,
		const board& b
	)
	{

		std::string name;

		if(position == 0)
		{
			name = "| P |";
		}
		else if(b.is_angular(position))
		{
			name = "|   |";
		}
		else if(current_box)
		{
			name = conf.get()->get_display_prop("box_" + current_box->get_category().get_name());
			name = "| " + name + " |"; 
		}

		return name;
	}


	std::ostream& operator<<(std::ostream& os, const playground& play)
	{

		constexpr short cell_width = 5;
		constexpr unsigned int full_row = play.board_.FIELD_SIZE / 4 + 1;
		constexpr unsigned int central_rows = full_row - 2;
		constexpr unsigned int med_row_width = cell_width * full_row + (full_row - 1) - cell_width;

		std::vector<std::shared_ptr<const player>> players = play.get_players();

		for(int i = 0; i < full_row; i++)
		{
			const box* current_box = play.board_.get_box(i);

			std::string name = _calc_name(i, play, current_box, play.configuration_, play.board_);

			os << name << " ";
		}

		os << std::endl;

		for(int i = 0; i < central_rows; i++)
		{
			unsigned int left = play.board_.FIELD_SIZE - i - 1;
			unsigned int right = full_row + i;

			const box* box_left = play.board_.get_box(left);
			const box* box_right = play.board_.get_box(right);
			
			std::string name_left = _calc_name(left, play, box_left, play.configuration_, play.board_);
			std::string name_right = _calc_name(left, play, box_right, play.configuration_, play.board_);

			os << std::setw(med_row_width) << std::left << name_left << std::right << name_right << std::endl;
		}


		for(int i =  play.board_.FIELD_SIZE - central_rows - 1; i >= full_row + central_rows; i--)
		{
			const box* current_box = play.board_.get_box(i);

			std::string name = _calc_name(i, play, current_box, play.configuration_, play.board_);

			os << name << " ";
		}

		for(auto it = players.begin(); it != players.end(); it++)
		{
			std::cout << it->get()->get_name() << std::endl;
		}

		return os;
	}
}