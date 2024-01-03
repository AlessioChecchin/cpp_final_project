#ifndef DICE_H
#define DICE_H

namespace prj
{
    class dice
    {
    private:
        unsigned int faces_;

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
