#include "player.h"
#include <string>

player::player(): name_{""}{}
std::string player::get_name() const { return name_; }
void player::set_name(const std::string& name){ name_ = name; }