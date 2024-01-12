#include "box.h"

namespace prj
{

box::box(const category& cat): category_{cat}, contract_{std::unique_ptr<contract>(new contract())}
{
	//std::unique_ptr<building> new_building = contract_->get_building()->upgrade();

	//contract_->set_building(std::move(new_building));

	//new_building = std::move(contract_->get_building()->upgrade());
	//contract_->set_building(std::move(new_building));


}

contract* box::get_contract()
{
	return contract_.get();
}

const contract* box::get_contract() const
{
	return contract_.get();
}

}