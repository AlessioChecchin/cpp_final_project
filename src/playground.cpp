/**
 * Playground implementation.
 * 
 * @author Alessio Checchin.
*/

#include "playground.h"

#include <memory>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

#include "players/player.h"
#include "board.h"
#include "config.h"
#include "logger/logger.h"

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
	if(player_index >= number_players())
		player_index = 0;
	return players_[player_index++];
}

bool playground::has_next_player() const
{
	return number_players() != 0;
}

std::string playground::get_box_name(unsigned int index) const
{
	const int side_lenght = (board_.FIELD_SIZE+4)/4;	// Board has (size*4 - 4) boxes 
	const int MAX_CHAR_INCREMENT = 26;	// from a to z there are 26 letters
	
	//Index is in range [0,size-1]
	if(index >= board_.FIELD_SIZE)
		throw std::invalid_argument("Index is out of board size");

	std::stringstream result;
    char start_char = 'A';
	int row_increment = 0;
    int col = -1;
    char row = '?';
    
	// Lower side
	// With size=8: 0...7 -> H8...H1
    if( index >= 0 * (side_lenght-1) && index <= 1 * (side_lenght-1))
    {
        row_increment = 1 * (side_lenght-1);
        col = side_lenght - index;
    }
	// Left side
	// With size=8: 7...14 -> H1,G1,...,A1
    else if( index >  1 * (side_lenght-1) && index <= 2 * (side_lenght-1))
    {
        row_increment = 2 * (side_lenght-1) - 1 * index;
        col = 1;
    }
	// Upper side
	// With size=8: 14...21 -> A1...A8
    else if( index >  2 * (side_lenght-1) && index <= 3 * (side_lenght-1))
    {
        row_increment = 0;
        col = index - (side_lenght-1)*2 + 1;
    }
	// Right side
	// With size=8: 21...0 -> A8,B8,...,H8
    else if( index >  3*(side_lenght-1) && index <  4*(side_lenght-1))
    {
        row_increment = - 3*(side_lenght-1) + index;
        col = side_lenght;
    }
    
    // Avaiable chars are only in range [A, ... ,Z]
    row = start_char + row_increment % (MAX_CHAR_INCREMENT);

    // If board is too large, we use double char to represent rows
    // E.g: with 27 rows we have A0, B0, ..., Z0, AA0, BB0
    for(int i=0; i<static_cast<int>(row_increment/MAX_CHAR_INCREMENT)+1; i++)
    	result << row;	
    result << col;

	return result.str();
}

unsigned int playground::number_players() const
{
	return players_.size();
}

void playground::add_player(std::shared_ptr<player> new_player)
{
	if(!new_player)
	{
		throw std::invalid_argument("Invalid player");
	}
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
	if(!to_remove)
		throw std::invalid_argument("Trying to remove null player");
	if(!is_playing(to_remove))
	{
		throw std::invalid_argument("Cannot remove a player which isn't player");
	}
	unsigned long int id = to_remove->id_;


	
	auto element = std::find_if(players_.begin(), players_.end(), [id](std::shared_ptr<player> p)
	{
		return p->get_id() == id;
	});
	
	//Fails silently.
	if(element == players_.end())	
	{
		return;
	}
	
	player_index--; //Necessary to avoid player_index invalidation

	// Find all ownership of the player. Set their contract owner to nullptr
	for(unsigned int pos : to_remove->ownerships_)
	{
		board_.get_box(pos)->get_contract()->set_owner(nullptr);
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
	if(!to_move)
	{
		throw std::invalid_argument("Invalid player");
	}
	if(!is_playing(to_move))
	{
		throw std::invalid_argument("The player is not playing");
	}

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
	//Add money to the player (<=> laps > 0)
	if(moving_forward && laps > 0)
	{
		for(int i=0; i<laps; i++)
		{
			logger& logger_ = logger_.get_logger();
			logger_ << "Giocatore "
        			<< to_move->get_id() 
        			<< " e' passato dal via e ha ritirato "
        			<< configuration_->get_bonus_cycle()
        			<< " fiorini"
        			<< std::endl;

			to_move->score_ += configuration_->get_bonus_cycle();
		}
	}
}

action playground::perform_action(std::shared_ptr<player> to_perform)
{
	if(!to_perform)
	{
		throw std::invalid_argument("Invalid player");
	}
	if(!is_playing(to_perform))
	{
		throw std::invalid_argument("Player is not playing here");
	}

	std::set<action> choices;

	box* player_box = board_.get_box(to_perform->position_);
	
	int buy_cost = 0;
	int upgrade_cost = 0;
	int stay_cost = 0;

	if(board_.is_angular(to_perform->position_))
	{
		// If the box is angular the user does nothing.
		choices.emplace(action::NOTHING);
	}
	else
	{
		// If the box does not have an owner, the player can buy it.
		std::shared_ptr<player> owner = board_.get_box(to_perform->position_)->get_contract()->get_owner();
		const building* current_building = board_.get_box(to_perform->position_)->get_contract()->get_building();

		if(owner == nullptr)
		{
			// If the box does not have a owner then the user can do nothing or buy the terrain.
			choices.emplace(action::NOTHING);

			buy_cost = configuration_->get_action_cost(action::BUY, player_box->get_category(), current_building);

			if(to_perform->score_ - buy_cost >= 0)
			{
				choices.emplace(action::BUY);
				choices.emplace(action::SHOW);
			}
		}
		else if(owner->id_ == to_perform->id_)
		{
			// If the user owns the box, then he can choose to do nothing.
			choices.emplace(action::NOTHING);

			if(player_box->get_contract()->get_building()->upgradable())
			{
				upgrade_cost = configuration_->get_action_cost(action::UPGRADE, player_box->get_category(), current_building);

				// If the building in the box is upgradable and he has moeney then he can upgrade it.
				if(to_perform->score_ - upgrade_cost >= 0)
				{
					choices.emplace(action::UPGRADE);
					choices.emplace(action::SHOW);
				}
			}
		}
		else
		{
			stay_cost = configuration_->get_action_cost(action::STAY, player_box->get_category(), current_building);

			// If the player can pay the the only action possibile is STAY.
			// Note that to_perform->decision MUST return a STAY action.
			if(to_perform->score_ - stay_cost >= 0)
			{
				choices.emplace(action::STAY);
			}
			// If the player can't pay the the only action possibile is LOSE.
			// Note that to_perform->decision MUST return a LOSE action.
			else
			{
				choices.emplace(action::LOSE);
			}
		}
	}

	// Decision acts as a middleware.
	action performed = to_perform->decision(board_.get_box(to_perform->position_), choices);

	// Check if the returned action is valid.
	if(choices.find(performed) == choices.end())
	{
		throw std::logic_error("Player can't perform this action now");
	}

	switch(performed)
	{
		case action::NOTHING:
			break;

		case action::BUY:
			// Note that the action is already validated previously
			to_perform->score_ -= buy_cost;

			player_box->get_contract()->set_owner(to_perform);

			// Save position of the terrain bought
			to_perform->ownerships_.push_back(to_perform->get_pos());
			break;
		
		case action::UPGRADE:
			// Note that the action is already validated previously
			to_perform->score_ -= upgrade_cost;

			// We already know that is upgradable.
			player_box->get_contract()->set_building(
				player_box->get_contract()->get_building()->upgrade()
			);
			break;
		
		case action::STAY:
			to_perform->score_ -= stay_cost;


			player_box->get_contract()->get_owner()->score_ += stay_cost;
			break;

		case action::LOSE:

			to_perform->score_ = 0;
			remove_player(to_perform);
		
		default: break;
	}

	return performed;
}

const box* playground::get_player_box(std::shared_ptr<player> my_player) const
{
	if(!my_player)
	{
		throw std::invalid_argument("Invalid player");
	}

	if(!is_playing(my_player))
	{
		throw std::invalid_argument("Invalid player");
	}

	return board_.get_box(my_player->position_);
}

// Protected methods

std::string playground::format_text(unsigned int position) const
{

	const box* current_box = board_.get_box(position);

	// Warning, current box may be null.
	std::string name;
	std::string building_suffix;

	// If is start box (current box is null)
	if(position == 0)
	{
		name = configuration_.get()->get_display_prop("box_start");
	}

	// Angular box (current_box is null)
	else if(board_.is_angular(position))
	{
		name = configuration_.get()->get_display_prop("box_angular");
	}
	else if(current_box)
	{
		name = configuration_.get()->get_display_prop("box_" + current_box->get_category().get_name());
	}

	// Gets the buiding name.
	if(current_box)
	{
		std::string building_name = current_box->get_contract()->get_building()->get_name();
		building_suffix = configuration_.get()->get_display_prop("suf_" + building_name);
	}
	
	return name + building_suffix;
}

std::string playground::format_label_players(const std::multimap<unsigned int, std::shared_ptr<const player>>& map, unsigned int position) const
{
	std::string formatted;

	// Getting player that are in the box of specified position
	for(auto it = map.begin(); it != map.end(); it++)
	{
		if(it->first == position)
		{
			formatted += std::to_string(it->second->get_id());
		}
	}

	return formatted;
}

std::string playground::format_label(const std::multimap<unsigned int, std::shared_ptr<const player>>& map, unsigned int position, unsigned int cell_width) const
{
	std::string formatted = format_text(position) + format_label_players(map, position);
	
	// If nothing is specified, then adapting is not performed.
	if(cell_width == 0)
	{
		return formatted;
	}

	return adapt_label_size(formatted, cell_width);
}

std::string playground::adapt_label_size(const std::string& original, unsigned int desired_size, char delimiter) const
{
	// Adapts size
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

	// If conditions for adapring size are not met then it just appends the delimiters.
	return delimiter + original+ delimiter;
}

std::ostream& operator<<(std::ostream& os, const playground& play)
{
	// Constants used for calculating the board gui.
	constexpr unsigned int default_cell_width = 3;
	constexpr unsigned int full_row = play.board_.FIELD_SIZE / 4 + 1;
	constexpr unsigned int central_rows = full_row - 2;
	constexpr unsigned int extra_spaces = 2;

	// Maps positions with players.
	std::multimap<unsigned int, std::shared_ptr<const player>> position_map;

	// Output buffering.
	std::vector<std::string> out_buf_top;
	std::vector<std::string> out_buf_bottom;

	unsigned int max_size_top = 0;
	unsigned int max_size_bottom = 0;

	// Creates the player map position.
	for(auto it = play.players_.begin(); it != play.players_.end(); it++)
	{
		position_map.insert({it->get()->get_pos(), *it});
	}

	// Generating top row (buffering is needed because we need to find the biggest label).
	for(int i = full_row + central_rows; i < play.board_.FIELD_SIZE - central_rows; i++)
	{
		const box* current_box = play.board_.get_box(i);
		out_buf_top.push_back(play.format_label(position_map, i));

		if(out_buf_top.back().size() > max_size_top)
		{
			max_size_top = out_buf_top.back().size();
		}
	}
	
	// Generating bottom row (buffering is needed because we need to find the biggest label).
	for(int i = full_row - 1; i >= 0; i--)
	{
		const box* current_box = play.board_.get_box(i);
		out_buf_bottom.push_back(play.format_label(position_map, i));

		if(out_buf_bottom.back().size() > max_size_bottom)
		{
			max_size_bottom = out_buf_bottom.back().size();
		}
	}
	
	// Calculated the cell_width.
	unsigned int cell_width = std::max(max_size_top, max_size_bottom);
	cell_width = std::max(cell_width, default_cell_width);

	// Adding two extra spaces for separators.
	cell_width += extra_spaces;

	const unsigned int med_row_width = cell_width * full_row + (full_row - 1);

	os << "   ";

	for(int i = 0; i < full_row; i++)
	{
		os << play.adapt_label_size(std::string(1, static_cast<char>('1' + i)), cell_width, ' ') << " ";
	}

	os << std::endl;
	os << "A  ";

	// Output top row.
	for(int i = 0; i < full_row; i++)
	{
		os << play.adapt_label_size(out_buf_top[i], cell_width) << " ";
	}

	os << std::endl;

	// Output middle rows.
	for(int i = 0; i < central_rows; i++)
	{
		unsigned int left = full_row + central_rows - i - 1;
		unsigned int right = play.board_.FIELD_SIZE - central_rows + i;
		const box* box_left = play.board_.get_box(left);
		const box* box_right = play.board_.get_box(right);
		
		std::string name_left = play.format_label(position_map, left, cell_width);

		std::string name_right = play.format_label(position_map, right, cell_width);

		os << static_cast<char>('A' + i + 1) << "  " << std::setw(med_row_width - name_right.size()) << std::left << name_left << std::right << name_right << std::endl;
	}

	os << static_cast<char>('A' + central_rows + 1) << "  ";

	// Output bottom row.
	for(int i = 0; i < full_row; i++)
	{
		os << play.adapt_label_size(out_buf_bottom[i], cell_width) << " ";
	}

	os << std::endl;

	return os;
}

} // prj