/**
 * Bot class.
 * 
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
     * Instantiate player with initial balance.
	 * @param balance Initial balance.
	 * @param configuration Configuration object.
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

	/**
	 * Configuration object.
	*/
	std::shared_ptr<config> configuration_;
};

} // prj

#endif  // BOT_H