/**
 * @author Jacopo Toniolo
 */
#ifndef HUMAN_H
#define HUMAN_H

#include "players/player.h"


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
    virtual void decision() override;
    
};

}
#endif  // HUMAN_H