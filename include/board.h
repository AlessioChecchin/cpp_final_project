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
	
	bool is_angular(unsigned int position) const;

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

//std::ostream& operator<<(std::ostream& out, )

}
#endif // BOARD_H