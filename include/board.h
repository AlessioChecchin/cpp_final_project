/**
 * Board class.
 * @author Alessio Checchin
*/

#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>

#include "box.h"
#include "config.h"

namespace prj
{

/**
 * A board holds the boxes of the field.
*/
class board
{
public:
	/**
	 * Default constructor.
	*/
	board(std::shared_ptr<config> configuration);
	
	/**
	 * Checks if is an angular box.
	 * @param position Position of the box to check.
	 * @return If the box in in angular position.
	*/
	bool is_angular(unsigned int position) const;

	/**
	 * Returns a non-owning pointer that allows to access a box.
	 * @param position The position of the box to get.
	 * @return A non-owning pointer to the box. Pointer lifetime is automatically handled.
	*/
	const box* get_box(unsigned int position) const;

	/**
	 * Returns a non-owning pointer that allows to access a box.
	 * @param position The position of the box to get.
	 * @return A non-owning pointer to the box. Pointer lifetime is automatically handled.
	*/
	box* get_box(unsigned int position);

    /**
	 * Size of the field.
	*/
	const static int FIELD_SIZE = 28;

protected:

    /**
	 * Array representing the field. THe board is the owner of the boxes and,
	 * for this reason, field_ is an array of unique_ptr.
	 * Furthermore the use of pointers allows flexibility regarding possibles
	 * polimorphic instances.
	*/
	std::array<std::unique_ptr<box>, FIELD_SIZE> field_;
};

}

#endif // BOARD_H