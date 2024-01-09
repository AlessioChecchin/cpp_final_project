/**
 * @author Jacopo Toniolo
*/

#include "game.h"
#include "config.h"
#include "players/bot.h"
#include "players/human.h"

namespace prj
{

game::game(std::shared_ptr<config> conf): conf_{conf}, playgr_{conf} 
{
    // Add players with initial budget
    add_players(conf_->get_initial_budget());

    

}

void game::add_players(unsigned int init_balance)
{
    // Add bots to playground
    for(int i=0 ; i<conf_->get_bot_number(); i++)
        playgr_.add_player(std::shared_ptr<player>(new bot(init_balance)));
    
    // Add human player to playground
    for(int i=conf_->get_bot_number(); i<conf_->get_human_number(); i++)
        playgr_.add_player(std::shared_ptr<player>(new human(init_balance)));
}

std::vector<std::shared_ptr<player>> game::retrieve_order()
{
    
}



}   