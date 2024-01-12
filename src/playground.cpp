#include "playground.h"

#include <memory>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include "players/player.h"
#include "board.h"
#include "config.h"

namespace prj
{

playground::playground(std::shared_ptr<config> configuration): board_{configuration}, players_{}, player_index{0}, configuration_{configuration}
{
	if(!configuration)
	{
		throw std::invalid_argument("Config can't be null");
	}
}

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
	// Automatically copied.
	// Player pointers allow to interact with the players that are inside the playground (this is by design)
	return players_;
}

std::vector<std::shared_ptr<const player>> playground::get_players() const
{
	std::vector<std::shared_ptr<const player>> result;
	for(auto it = players_.begin(); it != players_.end(); it++)
	{
		result.push_back(*it);
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
	(*element)->is_playing_ = false; 
	players_.erase(element);
}

bool playground::is_playing(std::shared_ptr<player> target) const
{
	if(!target) return false;
	unsigned int id = target->id_;
	return std::find_if(players_.begin(), players_.end(), [id](std::shared_ptr<player> p)
	{
		return p->get_id() == id;
	}) != players_.end();
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
	//Todo: Add money to the player
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

// The following functions are only used for formatting purposes. They are
// not meant to be public (even though they could be accessed if declared)
std::string _format_name
(
	unsigned int position,
	const playground& p,
	const box* current_box,
	const std::shared_ptr<config>& conf,
	const board& b
)
{
	// Warning, current box may be null.
	std::string name;
	std::string building_suffix;

	if(position == 0)
	{
		name = conf.get()->get_display_prop("box_start");
	}
	else if(b.is_angular(position))
	{
		name = conf.get()->get_display_prop("box_angular");
	}
	else if(current_box)
	{
		name = conf.get()->get_display_prop("box_" + current_box->get_category().get_name());
	}
	if(current_box)
	{
		std::string building_name = current_box->get_contract()->get_building()->get_name();
		building_suffix = conf.get()->get_display_prop("suf_" + building_name);
	}
	
	return name + building_suffix;
}


std::string _format_players(
	const std::multimap<unsigned int, std::shared_ptr<const player>>& map,
	unsigned int pos
)
{
	std::string formatted;

	for(auto it = map.begin(); it != map.end(); it++)
	{
		if(it->first == pos)
		{
			formatted += std::to_string(it->second->get_id());
		}
	}

	return formatted;
}

std::string _adapt_size(const std::string& original, unsigned int desired_size, char delimiter = '|')
{

	if(original.size() < desired_size)
	{
		if(desired_size - original.size() >= 2)
		{

			unsigned int left_offset = (desired_size - original.size()) / 2;
			unsigned int right_offset = desired_size - original.size() - left_offset;

			std::string centered = std::string(left_offset, ' ') + original + std::string(right_offset, ' ') ;
			centered[0] = delimiter;
			centered[desired_size - 1] = delimiter;

			return centered;
		}
	}

	return delimiter + original+ delimiter;
}

std::string _format(
	unsigned int position,
	const playground& p,
	const box* current_box,
	const std::shared_ptr<config>& conf,
	const board& b,
	const std::multimap<unsigned int, std::shared_ptr<const player>>& map,
	unsigned int cell_width = 0
)
{
	std::string formatted = _format_name(position, p, current_box, conf, b) + _format_players(map, position);
	
	if(cell_width == 0)
	{
		return formatted;
	}

	return _adapt_size(formatted, cell_width);
}

std::ostream& operator<<(std::ostream& os, const playground& play)
{
	constexpr unsigned int default_cell_width = 3;
	constexpr unsigned int full_row = play.board_.FIELD_SIZE / 4 + 1;
	constexpr unsigned int central_rows = full_row - 2;

	std::multimap<unsigned int, std::shared_ptr<const player>> position_map;

	std::vector<std::string> out_buf_top;
	std::vector<std::string> out_buf_bottom;

	unsigned int max_size_top = 0;
	unsigned int max_size_bottom = 0;

	for(auto it = play.players_.begin(); it != play.players_.end(); it++)
	{
		position_map.insert({it->get()->get_pos(), *it});
	}

	for(int i = 0; i < full_row; i++)
	{
		const box* current_box = play.board_.get_box(i);
		out_buf_top.push_back(_format(i, play, current_box, play.configuration_, play.board_, position_map));

		if(out_buf_top.back().size() > max_size_top)
		{
			max_size_top = out_buf_top.back().size();
		}
	}
	
	for(int i =  play.board_.FIELD_SIZE - central_rows - 1; i >= full_row + central_rows; i--)
	{
		const box* current_box = play.board_.get_box(i);
		out_buf_bottom.push_back(_format(i, play, current_box, play.configuration_, play.board_, position_map));

		if(out_buf_bottom.back().size() > max_size_bottom)
		{
			max_size_bottom = out_buf_bottom.back().size();
		}
	}
	
	unsigned int cell_width = std::max(max_size_top, max_size_bottom);
	cell_width = std::max(cell_width, default_cell_width);
	cell_width += 2;

	const unsigned int med_row_width = cell_width * full_row + (full_row - 1);

	os << "   ";

	for(int i = 0; i < full_row; i++)
	{
		os << _adapt_size(std::string(1, static_cast<char>('1' + i)), cell_width, ' ') << " ";
	}

	os << std::endl;

	os << "A  ";

	for(int i = 0; i < full_row; i++)
	{
		os << _adapt_size(out_buf_top[i], cell_width) << " ";
	}

	os << std::endl;

	for(int i = 0; i < central_rows; i++)
	{
		unsigned int left = play.board_.FIELD_SIZE - i - 1;
		unsigned int right = full_row + i;
		const box* box_left = play.board_.get_box(left);
		const box* box_right = play.board_.get_box(right);
		
		std::string name_left = _format(left, play, box_left, play.configuration_, play.board_, position_map, cell_width);

		std::string name_right = _format(right, play, box_right, play.configuration_, play.board_, position_map, cell_width);

		os << static_cast<char>('A' + i + 1) << "  " << std::setw(med_row_width - name_right.size()) << std::left << name_left << std::right << name_right << std::endl;
	}

	os << static_cast<char>('A' + central_rows + 1) << "  ";

	for(int i = 0; i < full_row; i++)
	{
		os << _adapt_size(out_buf_bottom[i], cell_width) << " ";
	}

	os << std::endl;

	return os;
}

} // prj