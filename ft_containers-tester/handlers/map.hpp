#ifndef HANDLER_MAP_HPP
# define HANDLER_MAP_HPP

#include "../Tester.hpp"
#include "../unit_tests/map_tests.hpp"

template <class Map>
void exec_test_map(wanted_tests_type tests = wanted_tests_type())
{
	new_type("Map");
	{
		//register tests
		register_test("insert_and_change_values", insert_and_change_values<Map>);
		register_test("constructors", constructors<Map>);
		register_test("insert_test", insert_test<Map>);
		register_test("operators", operators<Map>);
		register_test("iterators_tests", iterators_tests<Map>);
		register_test("capacity_tests", capacity_tests<Map>);
		register_test("erase_test", erase_test<Map>);
		register_test("swap_test", swap_test<Map>);
		register_test("find_tests", find_tests<Map>);
		register_test("bounds_tests", bounds_tests<Map>);
		register_test("const_values_test", const_values_test<Map>);
		register_test("count_test", count_test<Map>);
	}
	//launch tests
	global.start_test(tests);
}
#endif