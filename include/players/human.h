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
	 * @param current_box The box the player is in.
	 * @param choices A set of possible choices.
	 * @return One of the choices.
     */
    virtual action decision(const box* current_box, const std::set<action>& choices) override;

private:
	char wait_feedback(const std::string& message);
};

}
#endif  // HUMAN_H