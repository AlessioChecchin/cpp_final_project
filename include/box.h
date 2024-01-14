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

// Forward declaration.
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
	box(const category& my_category);

	/**
	 * Copy disabled, it contains non-copiable object.
	*/
	box(const box& my_box) = delete;

	/**
	 * Copy disabled, it contains non-copiable object.
	*/
	box& operator=(const box& my_box) = delete;

	/**
	 * Category getter.
	 * @return The category of the box.
	*/
	category get_category() const;

	/**
	 * Contract getter.
	 * @return The contract associated with the box.
	*/
	contract* get_contract();

	/**
	 * Contract getter.
	 * @return The contract associated with the box.
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