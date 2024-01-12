/**
 * @author Jacopo Toniolo
 */
#ifndef BOT_H
#define BOT_H

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
    virtual void decision() override;
};

}
#endif  // BOT_H