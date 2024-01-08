/**
 * @author Jacopo Toniolo
*/

#include "game.h"
#include "players/bot.h"
#include "players/human.h"

namespace prj
{

game::game(config& conf): conf_{conf}, playgr_{} 
{
    // Add bots to playground
    for(int i=0 ; i<conf_.get_bot_number(); i++)
        playgr_.add_player(std::shared_ptr<player>(new bot()));
    
    // Add human player to playground
    for(int i=conf_.get_bot_number(); i<conf_.get_player_number(); i++)
        playgr_.add_player(std::shared_ptr<player>(new human()));
    
}

}   