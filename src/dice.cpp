
#include <random>
#include <chrono>

#include "dice.h"

namespace prj
{

dice::dice(unsigned int faces): faces_{faces} {}

unsigned int dice::roll()
{
    // Generate seed
    std::random_device seed_generator;
    std::mt19937::result_type seed = seed_generator(); // result_type = unsigned int

    // Create RandomNumberGenerator from seed
    std::mt19937 rng(seed);

    // 'distribution' will transform the random unsigned int generated by 'rng'
    // to an unsigned int in [1, faces_]
    std::uniform_int_distribution<std::mt19937::result_type> distribution(1, faces_);

    return distribution(rng);
}

}