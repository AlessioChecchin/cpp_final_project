#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player
{
private:
	std::string name_;

public:
	player();
	std::string get_name() const;
	void set_name(const std::string& name);
};

#endif // PLAYER_H