#include "unit/unit_test_contract.h"
#include "contract.h"
#include "players/human.h"
#include "building/terrain.h"

#include <iostream>
#include <assert.h>

unit_test_contract::unit_test_contract(): test_suite{"unit_test_contract"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_contract::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_contract::test_getters, this)));
	add_test(test("setters", std::bind(&unit_test_contract::test_setters, this)));
}

void unit_test_contract::test_constructor()
{
	//testing default constructor
	prj::contract a;
	
	assert(("Failed to assign default owner to contract a", a.get_owner() == nullptr));
	//cannot test the default building because it is an unique_ptr
}

void unit_test_contract::test_getters()
{
	//testing getters
	prj::contract a;
	std::shared_ptr<prj::human> p;

	assert(("Failed to assign default owner to contract a", a.get_owner() == nullptr));
	assert(("Failed to get building to contract a", a.get_building()));
	//cannot test the default building because it is an unique_ptr

	a.set_owner(p);
	a.set_building(std::unique_ptr<prj::building>(new prj::terrain()));
	assert(("Failed to get owner to contract a", a.get_owner() == p));
	assert(("Failed to get building to contract a", a.get_building()));
	//cannot test the building because it is an unique_ptr
}

void unit_test_contract::test_setters()
{
	//testing setters
	prj::contract a;
	std::shared_ptr<prj::human> p;

	assert(("Failed to create default owner to contract a", a.get_owner() == nullptr));
	assert(("Failed to create default building to contract a", a.get_building()));
	//cannot test the default building because it is an unique_ptr

	a.set_owner(p);
	a.set_building(std::unique_ptr<prj::building>(new prj::terrain()));
	assert(("Failed to set owner to contract a", a.get_owner() == p));
	assert(("Failed to set building to contract a", a.get_building()));
	//cannot test the building because it is an unique_ptr	
}