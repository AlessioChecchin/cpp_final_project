/**
 * Box class.
 * @author Alessio Checchin
*/

#ifndef BOX_H
#define BOX_H

#include "contract.h"
#include "category.h"

namespace prj
{

/**
 * Represents a cell of a board.
*/
class box
{
public:

	/**
	 * Copy disabled, it contains non-copiable object.
	*/
	box(const box& b) = delete;

	/**
	 * Copy disabled, it contains non-copiable object.
	*/
	box& operator=(const building& b) = delete;

	/**
	 * Category getter.
	 * @return The category of the box.
	*/
	category get_category() const
	{
		return category_;
	}

private:
	/**
	 * Category of the box.
	*/
	category category_;
	
	/**
	 * Contract associated with the box.
	*/
	contract contract_;
};

}
#endif // BOX_H