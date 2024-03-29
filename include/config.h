/**
 * Configuration file.
 * 
 * @author Alessio Checchin
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <vector>
#include <string>

#include "players/action.h"
#include "category.h"
#include "building/building.h"

namespace prj
{

/**
 * This class contains all the information necessary to correctly configure the game.
 * It also allows convenient customization by a potential user, who can provide
 * different initialization techniques (for example, a subclass can load all necessary
 * information from a config. file).
*/
class config
{
public:

	/**
	 * Class used to archive all the information about a category.
	*/
	struct category_config
	{
		/**
		 * Constructor.
		*/
		category_config(const std::string c_name, unsigned int c_id, unsigned int c_number):
			name{c_name}, id{c_id}, number{c_number} {}

		/**
		 * Name of the category.
		*/
		std::string name{};

		/**
		 * Id of the category.
		*/
		unsigned int id{};

		/**
		 * Number of the category.
		*/
		unsigned int number{};
	};
public:

	/**
	 * Default constructor.
	*/
	config();

	/**
	 * Constructor for custom human and bot number.
	 * @param human_number Number of human players.
	 * @param bot_number Number of bot.
	*/
	config(unsigned int human_number, unsigned int bot_number);

	/**
	 * Copy disabled
	*/
	config(const config& my_config) = delete;

	/**
	 * Copy disabled
	*/
	config& operator=(const config& my_config) = delete;

	/**
	 * Max round number getter.
	 * @return The max number of round allowed in computer-only games
	*/
	virtual unsigned int get_round_number() const;

	/**
	 * Human players number getter.
	 * @return The number of human players in the game.
	*/
	virtual unsigned int get_human_number() const;

	/**
	 * Bot number getter.
	 * @return The number of bots in the game.
	*/
	virtual unsigned int get_bot_number() const;

	/**
	 * Initial budget getter.
	 * @return The initial budget of each player.
	*/
	virtual unsigned int get_initial_budget() const;

	/**
	 * Bonus cycle getter.
	 * @return The amount of bucks given to each player when a full cycle is completed.
	*/
	virtual unsigned int get_bonus_cycle() const;

	/**
	 * Dice number getter.
	 * @return The number of dices that each player throws each round.
	*/
	virtual unsigned int get_dice_number() const;

	/**
	 * Dice faces number getter.
	 * @return The number of faces of each dice.
	*/
	virtual unsigned int get_dice_faces_number() const;

	/**
	 * Buy land possibility getter.
	 * @param to_buy THe building to buy.
	 * @return Chance of a bot buying a land.
	*/
	virtual double get_buy_building_possibility(const building* to_buy) const;

	/**
	 * Log path getter.
	 * @return Path to the file that stores log infos.
	*/
	virtual std::string get_log_path() const;

	/**
	 * Available categories getter.
	 * @return The available categories.
	*/
	virtual std::vector<category_config> get_available_categories() const;

	/**
	 * Display prop getter.
	 * @param prop_name The property to get.
	 * @return The requested prof if exists, an empty string otherwise.
	*/
	virtual std::string get_display_prop(const std::string& prop_name) const;

	/**
	 * Returns the cost of an action of a building of a certain category.
	 * @param action_performed The performed action
	 * @param building_category The category of the building.
	 * @param current_building Current building.
	 * @return The cost of an action of a building of a certain category.
	*/
	virtual	int get_action_cost(action performed_action, const category building_category, const building* current_building) const;

protected:

	/**
	 * This matrix contains all the prices applied when buying or upgrading a building or terrain.
	 * 
	 * The default settings are:
	 * BUILDING      | ECONOMY       | STANDARD      | LUXURY
	 * ------------- | ------------- | ------------- | -------------
	 * TERRAIN       | 6             | 10            | 20
	 * HOUSE         | 3             | 5             | 10
	 * HOTEL         | 3             | 5             | 10 
	*/
	std::vector<std::vector<unsigned int>> buy_prices_{};

	/**
	 * This matrix contains all the prices applied when staying in a building.
	 * 
	 * The default settings are:
	 * BUILDING      | ECONOMY       | STANDARD      | LUXURY
	 * ------------- | ------------- | ------------- | -------------
	 * TERRAIN       | 0             | 0             | 0
	 * HOUSE         | 2             | 4             | 7
	 * HOTEL         | 4             | 8             | 14 
	*/
	std::vector<std::vector<unsigned int>> stay_prices_{};


	/**
	 * The max number of round allowed in only-computer games
	 * Default value: 100
	 */
	unsigned int round_number_{};

	/**
	 * The number of players playing.
	 * Default value: 0
	 */
	unsigned int human_number_{};

	/**
	 * The number of bots playing.
	 * Default value: 4.
	*/
	unsigned int bot_number_{};
	
	/**
	 * The initial budget of each player.
	 * Default value: 100.
	*/
	unsigned int initial_budget_{};
	
	/**
	 * The amount of bucks given to each player when a full cycle is completed.
	 * Default value: 20.
	*/
	unsigned int bonus_cycle_{};

	/**
	 * The number of dices that each player throws each round.
	 * Default value: 2.
	*/
	unsigned int dice_number_{};

	/**
	 * The number of faces of each dice.
	 * Default value: 6.
	*/
	unsigned int dice_faces_number_{};
	
	/**
	 * Chance of a bot buying building of a certain type.
	 * Default value: 0.25.
	*/
	std::map<unsigned int, double> buy_possibility_{};
	

	/**
	 * Symbols and texts used for displaying informations to the user.
	 * SYMBOL NAME   | VALUE       
	 * ------------- | ------------- 
	 * box_angular   | <space>
	 * box_start     | "P"
	 * box_economy   | "E"
	 * box_standard  | "S"
	 * box_luxury    | "L"
	 * suf_house     | "*"
	 * suf_hotel     | "^"
	 * suf_player    | "%d"
	*/
	std::map<std::string, std::string> display_props_{};

	/**
	 * Path to the file that stores log infos.
	*/
	std::string log_path_{};

	/**
	 * Available categories.
	*/
	std::vector<category_config> available_categories_;
};

} // prj

#endif// CONFIG_H