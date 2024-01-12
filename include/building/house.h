#ifndef HOUSE_H
#define HOUSE_H

#include "building.h"

namespace prj
{

class house: public building
{
public:
	house();
	virtual std::unique_ptr<building> upgrade() const override;
	virtual bool upgradable() const override;
};

} // prj

#endif