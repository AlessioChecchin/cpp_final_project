/**
 * @author Jacopo Toniolo
*/

#include <random>
#include <stdexcept>

#include "dice.h"

namespace prj
{

dice::dice(unsigned int faces): faces_{faces} 
{
    if(faces == 0)
        throw std::invalid_argument("Dices with 0 faces are not allowed");

    // Generate seed
    std::random_device seed_generator;
    std::mt19937::result_type seed = seed_generator(); // result_type = unsigned int

    // Create RandomNumberGenerator from seed
    generator_ = std::mt19937(seed);
}

dice::dice(dice&& b) : faces_{b.faces_}, generator_{std::move(b.generator_)}
{
    b.faces_ = 0;
}

dice& dice::operator=(dice&& b)
{
    faces_ = b.faces_;
    generator_ = std::move(b.generator_);
    
    b.faces_ = 0;

    return *this;
}

    

unsigned int dice::roll()
{
    // 'distribution' will transform the random unsigned int generated by 'rng'
    // to an unsigned int in [1, faces_]
    std::uniform_int_distribution<std::mt19937::result_type> distribution(1, faces_);

    return distribution(generator_);
}

}