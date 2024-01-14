/**
 * Possible actions.
 * 
 * @author Alessio Checchin
*/

#ifndef ACTION_H
#define ACTION_H

namespace prj
{
	enum class action
	{
		BUY = 0,
		STAY = 1,
		UPGRADE = 2,
		NOTHING = 3,
		LOSE = 4,
		SHOW = 5
	};
}

#endif // ACTION_H