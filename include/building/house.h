#ifndef HOUSE_H
#define HOUSE_H

#include "building/building.h"

namespace prj
{

class house: public building
{
public:
	house();
	virtual std::unique_ptr<building> upgrade() const;
	virtual bool upgradable() const;
};

} // prj

#endif