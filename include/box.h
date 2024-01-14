/**
 * Box class.
 * @author Alessio Checchin
*/

#ifndef BOX_H
#define BOX_H

#include <memory>

#include "contract.h"
#include "category.h"

namespace prj
{

class category;
class contract;

/**
 * Represents a cell of a board.
*/
class box
{
public:

	/**
	 * Constructor.
	*/
	box(const category& cat);

	/**
	 * Copy disabled, it contains non-copiable object.
	*/
	box(const box& b) = delete;

	/**
	 * Copy disabled, it contains non-copiable object.
	*/
	box& operator=(const box& b) = delete;

	/**
	 * Category getter.
	 * @return The category of the box.
	*/
	category get_category() const
	{
		return category_;
	}

	/**
	 * Contract getter.
	*/
	contract* get_contract();

	/**
	 * Contract getter.
	*/
	const contract* get_contract() const;

private:
	/**
	 * Category of the box.
	*/
	category category_;
	
	/**
	 * Contract associated with the box.
	*/
	std::unique_ptr<contract> contract_;
};

} // prj

#endif // BOX_H