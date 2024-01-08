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


    public:
        /**
         * Default constructor 
         */
        game(std::shared_ptr<config> conf);










};

}

#endif // GAME_H