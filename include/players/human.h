/**
 * Human class.
 * 
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
     * Default constructor.
     */
    human();

    /**
     * Instantiate player with initial balance.
	 * @param balance Initial balance.
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

	/**
	 * Waits for an input feedback.
	 * @param message The message to display.
	 * @return 's' for yes, 'n' for no, 'm' for show.
	*/
	char wait_feedback(const std::string& message);
};

} // prj

#endif  // HUMAN_H