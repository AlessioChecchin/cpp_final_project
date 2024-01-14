/**
 * @author Jacopo Toniolo
 */
#ifndef BOT_H
#define BOT_H

#include <set>

#include "player.h"
#include "config.h"

namespace prj
{
    
class bot : public player {

public:
    /**
     * Instantiate player with initial balance
     */
    bot(unsigned int balance, std::shared_ptr<config> configuration);

	/**
	 * Decision taken by the player
	 * @param current_box The box the player is in.
	 * @param choices A set of possible choices.
	 * @return One of the choices.
	 */
    virtual action decision(const box* current_box, const std::set<action>& choices) override;

private:
	std::shared_ptr<config> configuration_;
};

}
#endif  // BOT_H