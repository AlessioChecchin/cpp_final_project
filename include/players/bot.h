/**
 * @author Jacopo Toniolo
 */
#ifndef BOT_H
#define BOT_H

#include <set>

#include "player.h"

namespace prj
{
    
class bot : public player {

public:
    /**
     * Default constructor
     */
    bot();

    /**
     * Instantiate player with initial balance
     */
    bot(unsigned int balance);

    /**
     * Decision taken by the player
     */
    virtual action decision(const box* current_box, const std::set<action>& choices) override;
};

}
#endif  // BOT_H