/**
 * @author Jacopo Toniolo
 */
#ifndef HUMAN_H
#define HUMAN_H

#include <set>
#include "player.h"

namespace prj
{
    
class human : public player {
    
public:
    /**
     * Default constructor
     */
    human();

    /**
     * Instantiate player with initial balance
     */
    human(unsigned int balance);

    /**
     * Decision taken by the player
     */
    virtual action decision(const box* current_box, const std::set<action>& choices) override;
    
};

}
#endif  // HUMAN_H