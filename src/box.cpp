/**
 * Box implementation.
 * 
 * @author Alessio Checchin.
*/

#include "box.h"

namespace prj
{

box::box(const category& my_category): category_{my_category}, contract_{std::unique_ptr<contract>(new contract())}
{}

category box::get_category() const
{
	return category_;
}

contract* box::get_contract()
{
	// Returns non-owning pointer.
	return contract_.get();
}

const contract* box::get_contract() const
{
	// Returns non-owning pointer.
	return contract_.get();
}

} // prj