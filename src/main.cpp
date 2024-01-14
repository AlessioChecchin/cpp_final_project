#include <iostream>
#include <memory>

#include "playground.h"
#include "players/player.h"
#include "config.h"

//Temp
#include "dice.h"
#include "game.h"
#include "config.h"
#include "logger/logger.h"
#include "players/bot.h"

using namespace prj;

int main()
{

	// dice myDice(27);
	// for(int i=0; i<140000; i++)
	// 	std::cout << myDice.roll() << std::endl;

	// std::cout << "Hello world";

	playground p(std::shared_ptr<config>(new config())); // ambiguo senza prj::? Commentando linea 6 in player.h funziona
	
	logger& log = log.get_logger();
	
	log << std::endl;

	for(int i=0; i<28; i++)
		std::cout<<i<<" -> "<<p.get_box_name(i)<<std::endl;

//	auto tmp = std::unique_ptr<player>(new bot(100));
	game myGame(std::shared_ptr<config>(new config()));

	// for(int i=0; i<10; i++)
	// 	std::cout<<myGame.roll_dice()<<std::endl;

	// for(int i=0; i<10; i++)
	// 	p.add_player(std::unique_ptr<player>(new bot(100)));
	
	// auto temp = p.get_players();

	// for(int i=0; i<temp.size(); i++)
	// {
	// 	p.remove_player(temp[i]);
	// 	temp = p.get_players();
	// }


	//tmp->set_name("Gino");

	//std::cout << tmp->get_name();

	//p.add_player(std::move(tmp));
	//auto v = p.get_players();

	// for(auto it = v.begin(); it != v.end(); it++)
	// {
	// 	std::shared_ptr<player> ref = *it;

	// 	if(ref->get_name() == "Gino")
	// 	{
	// 		p.remove_player(ref);
	// 		std::cout << "Removed" << ref->get_name();
	// 	}

	// 	std::cout << ref->get_name();
	// }

	
	return 0;
}