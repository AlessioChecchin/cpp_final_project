#ifndef BOX_H
#define BOX_H

#include "contract.h"
#include "category.h"

namespace prj
{
class box
{
public:
	box(const box& b) = delete;
	box& operator=(const building& b) = delete;

	category get_category() const
	{
		return category_;
	}

private:
	category category_;
	contract contract_;
};

}
#endif // BOX_H