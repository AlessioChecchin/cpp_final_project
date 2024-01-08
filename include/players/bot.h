/**
 * @author Jacopo Toniolo
 */
#ifndef BOT_H
#define BOT_H

#include "players/player.h"


namespace prj
{
    
class bot : public player {
    virtual void decision() override;
};

}
#endif  // BOT_H