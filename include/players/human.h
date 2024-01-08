/**
 * @author Jacopo Toniolo
 */
#ifndef HUMAN_H
#define HUMAN_H

#include "players/player.h"


namespace prj
{
    
class human : public player {
    virtual void decision() override;
};

}
#endif  // HUMAN_H