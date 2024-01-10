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

namespace prj
{
/**
 * This class contains all the information necessary to correctly configure the game.
 * It also allows convenient customization by a potential user, who can provide
 * different initialization techniques (for example, a subclass can load all necessary
 * information from a config. file).
 * 
 * @author Alessio Checchin
 * @version 1.0.0
*/
class config
{
public:
	struct category_config
	{
		category_config(const std::string c_name, unsigned int c_id, unsigned int c_number):
			name{c_name}, id{c_id}, number{c_number} {}

		std::string name{};
		unsigned int id{};
		unsigned int number{};
	};
public:

	config();


	/**
	 * Copy disabled
	*/
	config(const config& b) = delete;

	/**
	 * Copy disabled
	*/
	config& operator=(const config& b) = delete;


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
	 * @return Chance of a bot buying a land.
	*/
	virtual double get_buy_land_possibity_bot() const;

	/**
	 * Buy house possibility getter.
	 * @return Chance of a bot buying a house.
	*/
	virtual double get_buy_house_possibility_bot() const;

	/**
	 * Buy hotel possibility getter.
	 * @return Chance of a bot buying a hotel.
	*/
	virtual double get_buy_hotel_possibility_bot() const;

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
	 * HOUSE         | 2             | 4             | 7
	 * HOTEL         | 4             | 8             | 14 
	*/
	std::vector<std::vector<unsigned int>> stay_prices_{};


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
	 * Chance of a bot buying land.
	 * Default value: 0.25.
	*/
	double buy_land_possibility_bot_{};

	/**
	 * Chance of a bot buying a house.
	 * Default value: 0.25.
	*/
	double buy_house_possibility_bot_{};

	/**
	 * Chance of a bot buying a hotel.
	 * Default value: 0.25.
	*/
	double buy_hotel_possibility_bot_{};

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