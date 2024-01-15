/**
 * House class.
 * 
 * @author Giulio Cattelan
*/

#ifndef HOUSE_H
#define HOUSE_H

#include "building.h"
#include <memory>

namespace prj
{

class house: public building
{
public:

	/**
	 * Constructor.
	*/
	house();

	/**
	 * Returns an instance of hotel.
	 * @return An instance of hotel.
	*/
	virtual std::unique_ptr<building> upgrade() const override;

	/**
	 * Returns true, is upgradable.
	 * @return true.
	*/
	virtual bool upgradable() const override;
};

} // prj

#endif // HOUSE_H