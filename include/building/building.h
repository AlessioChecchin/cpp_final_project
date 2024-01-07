/**
 * Abstract building.
 * 
 * @author Alessio Checchin
*/

#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <memory>

namespace prj
{

/**
 * Abstract class that represents a generic building.
*/
class building
{
public:

	/**
	 * Copy is disabled because this class must be extended.
	*/
	building(const building& b) = delete;

	/**
	 * Copy is disabled because this class must be extended.
	*/
	building& operator=(const building& b) = delete;

	/**
	 * Building name getter.
	 * @return The name of the building.
	*/
	virtual std::string get_name() const
	{
		return name_;
	}

	/**
	 * Returns the id of the building.
	*/
	virtual unsigned int get_id() const
	{
		return id_;
	}

	/**
	 * Returns an instance of an upgraded building.
	 * @throw If the building is not upgradable.
	*/
	virtual std::unique_ptr<building> upgrade() const = 0;
	
	/**
	 * Returns if the building is upgradable.
	*/
	virtual bool upgradable() const = 0;

protected:

	/**
	 * Constructor that allows initialization for subclasses.
	*/
	building(const std::string& name, unsigned int id);

	/**
	 * Building name.
	*/
	std::string name_;

	/**
	 * Building id.
	*/
	unsigned int id_;
};

}

#endif // BUILDING_H