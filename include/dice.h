/**
 * Dice class.
 * @author Jacopo Toniolo
*/
#ifndef DICE_H
#define DICE_H

#include <random>

namespace prj
{
    class dice
    {
    private:
        unsigned int faces_;
        std::mt19937 generator; //random number generator

    public:
        /**
         * Default constructor
         */
        dice(unsigned int faces);

        /**
         * Roll the dice 
         * @return Random number between 1 and "faces"
         */
        unsigned int roll();
    };
}
#endif //DICE
