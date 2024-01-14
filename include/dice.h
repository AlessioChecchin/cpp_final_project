/**
 * Dice class.
 * 
 * @author Jacopo Toniolo
*/
#ifndef DICE_H
#define DICE_H

#include <random>

namespace prj
{

class dice
{
public:
	/**
	 * Default constructor
	 * @throws std::invalid_argument
	 */
	dice(unsigned int faces);

	/**
	 * Construct dice by seed
	 * @param faces Number of faces
	 * @param int Seed to use
	 * @throws std::invalid_argument
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
	dice(const dice& my_dice) = delete;
	
	/**
	 * Copy disabled
	*/
	dice& operator=(const dice& my_dice) = delete;

	/**
	 * Move constructor
	 */
	dice(dice&& my_dice);

	/**
	 * Move assignment.
	 */
	dice& operator=(dice&& my_dice);

private:
	/**
	 * Number of faces.
	*/
	unsigned int faces_;

	/**
	 * Random generator.
	*/
	std::mt19937 generator_;
};

} // prj

#endif // DICE_H
