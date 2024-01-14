/**
 * Terrain class.
 * 
 * @author Alessio Checchin
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include "building.h"
#include <memory>

namespace prj
{

class terrain: public building
{
public:

	/**
	 * Terrain constructor.
	*/
	terrain();

	/**
	 * Returns an instance of house.
	 * @return An instance of house.
	*/
	virtual std::unique_ptr<building> upgrade() const override;

	/**
	 * Returns true, is upgradable.
	 * @return true.
	*/
	virtual bool upgradable() const override;
};

} // prj

#endif // TERRAIN_H