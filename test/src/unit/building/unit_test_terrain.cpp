#include "unit/building/unit_test_terrain.h"
#include "building/terrain.h"

#include <iostream>
#include <assert.h>

unit_test_terrain::unit_test_terrain(): test_suite{"unit_test_terrain"}
{
	// Binding method. Based on the current test structure
	// we are sure that test object does not outlive the current class instance.
	add_test(test("constructor", std::bind(&unit_test_terrain::test_constructor, this)));
	add_test(test("getters", std::bind(&unit_test_terrain::test_getters, this)));
	add_test(test("methods", std::bind(&unit_test_terrain::test_methods, this)));
}

void unit_test_terrain::test_constructor()
{
	//testing default constructor
	prj::terrain a;

	assert(("Failing to create terrain object a:", a.get_name() == "terrain"));
	assert(("Failing to create terrain object a:", a.get_id() == 0));
}

void unit_test_terrain::test_getters()
{
	//testing getters
	prj::terrain a;

	assert(("Failing to create terrain object a:", a.get_name() == "terrain"));
	assert(("Failing to create terrain object a:", a.get_id() == 0));
}

void unit_test_terrain::test_methods()
{
	//testing upgrade()
	prj::terrain a;

	assert(("Failing to upgrade the object (it shouldn't be possible)", a.upgrade()));

	//testing upgradable()
	prj::terrain b;

	assert(("Failing to check if the object is upgradable (it shouldn't be possible)", b.upgradable() == true));
	// "== true" is there for better readability
}