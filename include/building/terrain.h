#ifndef TERRAIN_H
#define TERRAIN_H

#include "building/building.h"

namespace prj
{

class terrain: public building
{
public:
	terrain();
	virtual std::unique_ptr<building> upgrade() const;
	virtual bool upgradable() const;
};

} // prj

#endif