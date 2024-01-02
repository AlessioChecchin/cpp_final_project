#ifndef BOARD_H
#define BOARD_H

#include <array>

#include "box.h"

namespace prj
{
    class board
    {
    public:
        /**
		 * Size of the field.
		*/
		const static int FIELD_SIZE = 28;
    protected:
        /**
		 * Array representing the field.
		*/
		std::array<box, FIELD_SIZE> field_;
    };
}
#endif // BOARD_H