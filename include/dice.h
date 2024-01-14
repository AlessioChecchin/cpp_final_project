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
        std::mt19937 generator_; //random number generator

    public:
        /**
         * Default constructor
         */
        dice(unsigned int faces);

        /**
         * Construct dice by seed
         * @param faces Number of faces
         * @param int Seed to use 
         */
        dice(unsigned int faces, unsigned int seed);

        /**
         * Roll the dice 
         * @return Random number between 1 and "faces"
         */
        unsigned int roll();

        /**
	     * Copy disabled
	    */
	    dice(const dice& b) = delete;
    
	    /**
	     * Copy disabled
	    */
	    dice& operator=(const dice& b) = delete;

        /**
         * Move constructor
         */
        dice(dice&& b);

        /**
         * Move assignment
         */
        dice& operator=(dice&& b);
        
    };
}
#endif //DICE
