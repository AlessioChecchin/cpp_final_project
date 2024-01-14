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
#include "logger/logger.h"

namespace prj
{
class game
{
    private:
        std::shared_ptr<config> conf_;
        playground playgr_;
        std::vector<dice> dices;
        logger& logger_;

        /**
         * Order players with dice rolling
         * @param players The map containing players 
         */
        void order_players(std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>>& players);

        /**
         * Create players
         */
        std::multimap<unsigned long int , std::shared_ptr<player>, std::greater<unsigned long int>>  create_players(unsigned int init_balance);

        /**
         * Roll dices and save their value
         * @param dice_number The number of dices to roll
         * @return unsigned long int The total score 
         */
        unsigned long int roll_dice();

        /**
         * Get the last dice roll
         * @return Last roll value
         */
        unsigned long int last_roll();

        /**
         * 
         * @param p Target Player
         */
        void log_start_bonus(std::shared_ptr<player> p) const;

        /**
         * Logs "dice rolled" event
         * @param p Target Player
         * @param score 
         */
        void log_dice_rolled(std::shared_ptr<player> p, int score) const;

        /**
         * Logs "player arrived at position" event
         * @param p Target Player
         */
        void log_arrived(std::shared_ptr<player> p) const;

        /**
         * Logs "player bought house" event
         * @param p Target Player
         */
        void log_bought_house(std::shared_ptr<player> p) const;

        /**
         * Logs "player bought terrain" event
         * @param p Target Player
         */
        void log_bought_terrain(std::shared_ptr<player> p) const;

        /**
         * Logs "player bought hotel" event
         * @param p Target Player
         */
        void log_bought_hotel(std::shared_ptr<player> p) const;

        /**
         * Logs "payer paid amount to payee" event
         * @param payee Player who's receving the amount
         * @param payer Player who's paying the amount
         * @param amount The amount of money
         */
        void log_fee(std::shared_ptr<player> payee, std::shared_ptr<player> payer, unsigned int amount) const;

        /**
         * Logs "round ended" event
         * @param p Target Player
         */
        void log_turn_ended(std::shared_ptr<player> p) const;

        /**
         * Logs "player eliminated" event
         * @param p Target Player
         */
        void log_eliminated(std::shared_ptr<player> p) const;

        /**
         * Logs "player won" event
         * @param p Target Player
         */
        void log_win(std::shared_ptr<player> p) const;



    public:
        /**
         * Default constructor 
         */
        game(std::shared_ptr<config> conf);

        /**
         * Run the game
         */
        void run();

        

};

}

#endif // GAME_H