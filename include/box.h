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

	contract* get_contract();

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

}
#endif // BOX_H