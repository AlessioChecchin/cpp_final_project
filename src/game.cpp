/**
 * @author Jacopo Toniolo
*/

#include <iterator>
#include <map>

#include "dice.h"
#include "config.h"
#include "players/bot.h"
#include "players/human.h"
#include "game.h"
#include "logger/logger.h"
namespace prj
{
game::game(std::shared_ptr<config> conf): conf_{conf}, playgr_{conf}, logger_{logger_.get_logger()}
{

	std::cout << playgr_ << std::endl;   
    // Create players with initial budget
    auto tempPlayers = create_players(conf_->get_initial_budget());

    // Order players with dice rolling and add the to playground
    order_players(tempPlayers);
    auto players = playgr_.get_players();

    //TEST
    for(int i=0; i<players.size(); i++)
        std::cout<<"Player "<<players[i]->get_id()<<std::endl;

    // Game continues until someone wins or it's a bot-game (with max number of rounds)
    // Rounds are in range [1, conf_->round_number]
    bool game_end = false;
    unsigned int round_counter = 0;    

    while(!game_end)
    {  
        round_counter++;
        ////////////////////////////////////////////////////////////////////////////////////////v
        auto current_player = playgr_.next_player();

        // Move player
        playgr_.move_player(current_player, roll_dice());



        // Per test - da togliere
        game_end = true;
        ////////////////////////////////////////////////////////////////////////////////////////v

        // ------ Bisogna tenere i turni max anche per partite human-bot
        if(round_counter==conf_->get_round_number())
            game_end = true;

        // It's a human or bot-only game
        //if(qualcuno vince) game_end = true;
    }
}

void game::order_players(std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>>& players)
{
    std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>> tempMap;
    std::multimap<unsigned long int , std::shared_ptr<player>>::iterator it, prevIt;

    it = players.begin();
    prevIt = it++;
    bool is_copying = false;

    /**
     * This code loops through the map of players. If it finds two or more players who's score is the same
     * it puts those player inside a tempMap.
     * The player is saved in tempMap with a new dice_roll() as key.
     * As soon as the iterator reaches the end of the sequence of player with same score,
     * tempMap (which contains player with a new score) is checked again with this algorithm
     * 
     * If a player has a unique score, it is added to playground
     */
    for(prevIt; prevIt != players.end(); prevIt++)
    {
        if(it == players.end() || prevIt->first != it->first)
        {
            // prevIt is still poiting to a player who had the same score of others
            if(is_copying)
            {
                tempMap.insert({roll_dice(), prevIt->second});
                log_dice_rolled(prevIt->second, last_roll());
                is_copying = false;
                
                // Check if second dice_roll succeeded
                if(tempMap.size() != 0)
                {
                    order_players(tempMap);  
                    tempMap.clear();
                }
            }
            // prevIt is pointing to a player who's score is unique. The player is sent to playground
            else
            {
                playgr_.add_player(prevIt->second);
            } 
        }
        // player pointed by prevIt doesn't have a unique score
        else if(prevIt->first == it->first)
        {
            tempMap.insert({roll_dice(), prevIt->second});
            log_dice_rolled(prevIt->second, last_roll());
            is_copying = true;
        }       

        it++;
    }
}


std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>> game::create_players(unsigned int init_balance)
{
    std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>> players;
    
    // Add bots to playground
    for(int i=0 ; i<conf_->get_bot_number(); i++)
    {
        std::shared_ptr<player> player(new bot(init_balance));
        log_dice_rolled(player, roll_dice());

        players.insert({last_roll(), player});
    }
    
    // Add human player to playground
    for(int i=conf_->get_bot_number(); i<conf_->get_human_number(); i++)
    {
        std::shared_ptr<player> player(new human(init_balance));
        
        log_dice_rolled(player, roll_dice());
        players.insert({last_roll(), player});
    }
    
    return players; 
}

unsigned long int game::roll_dice()
{
    // If not already existing, create dices
    if(dices.size() == 0)
        for(int i=0; i<conf_->get_dice_number(); i++)
            dices.push_back(std::move(dice(6)));
    
    // Roll and sum the results
    last_roll_ = 0;
    for(int i=0; i<dices.size(); i++)
       last_roll_ += dices[i].roll();

    return last_roll();
}

unsigned long int game::last_roll()
{
    return last_roll_;
}


void game::log_start_bonus(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
        << p->get_id() 
        << " e' passato dal via e ha ritirato "
        << conf_->get_bonus_cycle()
        << " fiorini"
        << std::endl;
}
void game::log_dice_rolled(std::shared_ptr<player> p, int score) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha tirato i dadi ottenendo un valore di "
            << score 
            << std::endl;

}
void game::log_arrived(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " e' arrivato alla casella "
            << p->get_pos()
            << std::endl;
}
void game::log_bought_house(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha costruito una casa sul terreno "
            << p->get_pos()
            << std::endl;
}
void game::log_bought_terrain(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha acquistato il terreno "
            << p->get_pos()
            << std::endl;
}
void game::log_bought_hotel(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha migliorato una casa in albergo sul terreno "
            << p->get_pos()
            << std::endl;
}
void game::log_fee(std::shared_ptr<player> payee, std::shared_ptr<player> payer, unsigned int amount) const
{
    logger_ << "Giocatore "
            << payer->get_id() 
            << " ha pagato "
            << amount
            << " fiorini a giocatore "
            << payee->get_id()
            << " per pernottamento nella casella "
            << payer->get_pos()
            << std::endl;
}
void game::log_round_ended(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha finito il turno"
            << std::endl;
}
void game::log_eliminated(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " e' stato eliminato"
            << std::endl;
}
void game::log_win(std::shared_ptr<player> p)  const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha vinto la partita"
            << std::endl;
}

}   