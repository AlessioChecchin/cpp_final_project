/**
 * Game classe
 * @author Jacopo Toniolo
 */
#ifndef GAME_H
#define GAME_H

#include <map>

#include "config.h"
#include "playground.h"
#include "dice.h"

namespace prj
{
class game
{
private:
    std::shared_ptr<config> conf_;
    playground playgr_;
    std::vector<dice> dices;
public:
    /**
     * Default constructor 
     */
    game(std::shared_ptr<config> conf);
    /**
     * Create players
     */
    std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>>  create_players(unsigned int init_balance);
    /**
     * Order players with dice rolling
     * @param players The map containing players 
     */
    void order_players(std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>>& players);
    /**
     * Roll dices and get their value
     * @param dice_number The number of dices to roll
     * @return unsigned long int The total score 
     */
    unsigned long int roll_dice();
};

}

#endif // GAME_H