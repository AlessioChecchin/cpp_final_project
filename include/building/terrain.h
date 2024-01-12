#ifndef TERRAIN_H
#define TERRAIN_H

#include "building.h"

namespace prj
{

class terrain: public building
{
public:
	terrain();
	virtual std::unique_ptr<building> upgrade() const override;
	virtual bool upgradable() const override;
};

} // prj

#endif