/**
 * Game classe
 * @author Jacopo Toniolo
 */
#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "playground.h"

namespace prj
{
class game
{
    private:
        std::shared_ptr<config> conf_;
        playground playgr_;
        std::shared_ptr<player> game_order[];

    public:
        /**
         * Default constructor 
         */
        game(std::shared_ptr<config> conf);

        /**
         * Add players to the game
         */
        void add_players(unsigned int init_balance);

        /**
         * Get playing order 
         * @return Vector of players with the defined random order
         */
        std::vector<std::shared_ptr<player>> retrieve_order();
    








};

}

#endif // GAME_H