#include "board.h"
#include "box.h"
#include "category.h"
#include "dice.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>

namespace prj
{

board::board()
{
	constexpr int N_ECONOMY = 8;
	constexpr int N_STANDARD = 10;
	constexpr int N_LUXURY = 6;

	constexpr int ENTROPY = 5000;

	std::vector<int> positions;

	// Initializing an array of side positions.
	for(int i = 0; i < FIELD_SIZE; i++)
	{
		if(!is_angular(i))
		{
			positions.push_back(i);
		}
	}

	// Generates numbers from in the range [0, size]

    // Generate seed
    std::random_device seed_generator;
    std::mt19937::result_type seed = seed_generator();
    std::mt19937 rng(seed);

	// Mixing
	for(int i = 0; i < FIELD_SIZE * ENTROPY; i++)
	{
	    std::uniform_int_distribution<std::mt19937::result_type> distribution(1, positions.size());

		int x = distribution(rng) - 1;
		int y = distribution(rng) - 1;

		std::swap(positions[x], positions[y]);
	}

	int j = 0;

	for(int i = 0; i < N_ECONOMY; i++)
	{
		field_[positions[j++]] = std::unique_ptr<box>(new box(category("economy", 0)));
	}
	
	for(int i = 0; i < N_STANDARD; i++)
	{
		field_[positions[j++]] = std::unique_ptr<box>(new box(category("standard", 1)));
	}

	for(int i = 0; i < N_LUXURY; i++)
	{
		field_[positions[j++]] = std::unique_ptr<box>(new box(category("luxury", 2)));
	}
};

bool board::is_angular(unsigned int pos) const
{
	return pos == 0 || pos % (FIELD_SIZE / 4) == 0;
}

} // prj