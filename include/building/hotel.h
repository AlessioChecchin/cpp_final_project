#ifndef HOTEL_H
#define HOTEL_H

#include "building/building.h"

namespace prj
{

class hotel: public building
{
public:
	hotel();
	virtual std::unique_ptr<building> upgrade() const override;
	virtual bool upgradable() const override;
};

} // prj

#endif