/**
 * Hotel class.
 * 
 * @author Giulio Cattelan
*/

#ifndef HOTEL_H
#define HOTEL_H

#include "building.h"
#include <memory>

namespace prj
{

class hotel: public building
{
public:
	
	/**
	 * Constructor.
	*/
	hotel();

	/**
	 * In this case throws an exception if called. It's the highest building in the hierarchy.
	 * @throws std::invalid_argument
	*/
	virtual std::unique_ptr<building> upgrade() const override;

	/**
	 * In this case returns false. Hotel is not upgradable.
	 * @return false.
	*/
	virtual bool upgradable() const override;
};

} // prj

#endif // HOTEL_H