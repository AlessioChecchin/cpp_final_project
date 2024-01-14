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
}


void game::run()
{
    // Create dices
    for(int i=0; i<conf_->get_dice_number(); i++)
        dices.push_back(std::move(dice(6)));

    // Create players with initial budget
    auto tempPlayers = create_players(conf_->get_initial_budget());

    // Order players with dice rolling and add them to playground
    order_players(tempPlayers);

    for(int round=0; round<conf_->get_round_number() && playgr_.number_players() > 1; round++)
    {
        for(int turn=0; turn<playgr_.number_players() && playgr_.number_players() > 1; turn++)
        {
            // Get next player
            std::shared_ptr<player> current_player = playgr_.next_player();

            // Roll dice
            unsigned int temp_roll = roll_dice();
            log_dice_rolled(current_player, temp_roll);

            // Move player
            playgr_.move_player(current_player, temp_roll);
            log_arrived(current_player);

			action result;
			
			do
			{
				result = playgr_.perform_action(current_player);

				if(result == action::SHOW)
				{
                    // Print field
					std::cout << playgr_ ;
                    std::cout << std::endl;

                    // Print players scores
                    auto temp_players = playgr_.get_players();
                    for(int i=0; i<playgr_.number_players(); i++)
                        std::cout   << "Giocatore " 
                                    << temp_players[i]->get_id() << ": " 
                                    << temp_players[i]->get_score() << std::endl;
                    
                    std::cout << std::endl;
                    // Print properties
                    for(int i=0; i<playgr_.number_players(); i++)
                    {
                        auto temp_ownerships = temp_players[i]->get_ownerships();
                        
                        std::cout   << "Giocatore "
                                    << temp_players[i]->get_id() << ": ";

                        for(int a=0; a<temp_ownerships.size(); a++)
                        {
                            std::cout << playgr_.get_box_name(temp_ownerships[a]) << ", ";
                        }
                        std::cout << std::endl;
                    }
                     
				}
			}
			while(result == action::SHOW);


			switch(result)
			{
				case action::NOTHING:
                {
					break;
                }
				case action::BUY:
                {
                    log_bought_terrain(current_player);
					break;
                }
				case action::UPGRADE:
                {
                    log_bought_house(current_player);
					break;
                }
				case action::STAY:
                {
                    // Get payee and payment amount
                    auto payee = playgr_.get_player_box(current_player)->get_contract()->get_owner();
                    auto building_category = playgr_.get_player_box(current_player)->get_category();
                    auto building = playgr_.get_player_box(current_player)->get_contract()->get_building();
                    unsigned int amount = conf_->get_action_cost(action::STAY, building_category, building);

                    log_fee(payee, current_player, amount);
					break;
                }
				case action::LOSE:
                {
					log_eliminated(current_player);
					break;
                }
			}

            log_turn_ended(current_player);
        }

        logger_ << std::endl;
    }

    // Last player in game wins
    if(playgr_.number_players() == 1)
    {
        log_win(playgr_.next_player());
    }
    // Game ended due to max round number reached.
    else
    {
        // Remaining players are saved in a descending multimap with key equal to player's score
        std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>> players;
        for(int i=0; i<playgr_.number_players(); i++)
        {
            std::shared_ptr<player> temp_player = playgr_.next_player();
            players.insert({temp_player->get_score(), temp_player});
        }

        // Player's who's score is the highest are logged
        std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>>::iterator it = players.begin();

        int max_score = it->first;
        for(it; it != players.end(); it++)
        {
            if(it->first == max_score)
                log_win(it->second);
        }
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
                unsigned int temp_roll = roll_dice();
                tempMap.insert({temp_roll, prevIt->second});
                
                log_dice_rolled(prevIt->second, temp_roll);
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
            unsigned int temp_roll = roll_dice();
            tempMap.insert({temp_roll, prevIt->second});
            log_dice_rolled(prevIt->second, temp_roll);
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
        std::shared_ptr<player> player(new bot(init_balance, conf_));

        unsigned int temp_roll = roll_dice();
        log_dice_rolled(player, temp_roll);

        players.insert({temp_roll, player});
    }
    
    // Add human player to playground
    for(int i=0; i<conf_->get_human_number(); i++)
    {
        std::shared_ptr<player> player(new human(init_balance));
        
        unsigned int temp_roll = roll_dice();
        log_dice_rolled(player, temp_roll);

        players.insert({temp_roll, player});
    }
    
    return players; 
}

unsigned long int game::roll_dice()
{   
    // Roll and sum the results
    unsigned int result = 0;
    for(int i=0; i<dices.size(); i++)
       result += dices[i].roll();

    return result;
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
            << playgr_.get_box_name(p->get_pos())
            << std::endl;
}
void game::log_bought_house(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha costruito una casa sul terreno "
            << playgr_.get_box_name(p->get_pos())
            << std::endl;
}
void game::log_bought_terrain(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha acquistato il terreno "
            << playgr_.get_box_name(p->get_pos())
            << std::endl;
}
void game::log_bought_hotel(std::shared_ptr<player> p) const
{
    logger_ << "Giocatore "
            << p->get_id() 
            << " ha migliorato una casa in albergo sul terreno "
            << playgr_.get_box_name(p->get_pos())
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
            << playgr_.get_box_name(payer->get_pos())
            << std::endl;
}
void game::log_turn_ended(std::shared_ptr<player> p) const
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