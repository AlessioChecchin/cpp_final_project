/**
 * Board implementation.
 * 
 * @author Alessio Checchin
*/

#include "board.h"

#include <vector>
#include <algorithm>
#include <stdexcept>

#include "box.h"
#include "category.h"
#include "dice.h"
#include "config.h"

namespace prj
{

board::board(std::shared_ptr<config> configuration)
{
	if(!configuration)
	{
		throw std::invalid_argument("Config can't be null");
	}

	// Reading categories config.
	std::vector<config::category_config> cat_config = configuration->get_available_categories();

	// Checking that the configuration is correct.
	unsigned int sum = 0;
	for(config::category_config& c: cat_config)
	{
		sum += c.number;
	}

	if(sum != FIELD_SIZE - 4)
		throw std::invalid_argument("Invalid configuration file, invalid number of categories");

	// Entropy used for mixing.
	constexpr int ENTROPY = 5000;

	std::vector<int> positions;

	// Initializing an array of side positions.
	for(int i = 0; i < FIELD_SIZE; i++)
	{
		if(!is_angular(i))
		{
			positions.push_back(i);
		}
		else
		{
			field_[i] = nullptr;
		}
	}

	// Generates numbers from in the range [0, size]
	dice generator(positions.size());

	// Mixing
	for(int i = 0; i < FIELD_SIZE * ENTROPY; i++)
	{
		int x = generator.roll() - 1;
		int y = generator.roll() - 1;

		std::swap(positions[x], positions[y]);
	}

	int j = 0;

	for(int i = 0; i < cat_config.size(); i++)
	{
		for(int k = 0; k < cat_config[i].number; k++)
		{
			field_[positions[j++]] = std::unique_ptr<box>(new box(category(cat_config[i].name, cat_config[i].id)));
		}
	}
};

bool board::is_angular(unsigned int pos) const
{
	return pos == 0 || pos % (FIELD_SIZE / 4) == 0;
}

box* board::get_box(unsigned int position)
{
	if(position >= FIELD_SIZE) throw std::out_of_range("Out of range");
	return field_[position].get();
}

const box* board::get_box(unsigned int position) const
{
	if(position >= FIELD_SIZE) throw std::out_of_range("Out of range");
	return field_[position].get();
}


} // prj