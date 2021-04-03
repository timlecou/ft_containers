#ifndef HANDLER_VECTOR_HPP
# define HANDLER_VECTOR_HPP

#include <map>
# include "../Tester.hpp"
# include "../unit_tests/vector_tests.hpp"

template<class vector>
void exec_test_vector(wanted_tests_type tests = wanted_tests_type())
{
	new_type("vector");
	{
		//register tests
		register_test("capacity_vector_tests", capacity_vector_tests<vector>);
		register_test("reserve_vector_tests", reserve_vector_tests<vector>);
		register_test("iterators_vector_tests", iterators_vector_tests<vector>);
		register_test("element_access_vector_tests", element_access_vector_tests<vector>);
		register_test("resize_vector_tests", resize_vector_tests<vector>);
		register_test("constructors_vector_tests", constructors_vector_tests<vector>);
		register_test("operators_vector_tests", operators_vector_tests<vector>);
		register_test("swap_vector_tests", swap_vector_tests<vector>);
		register_test("clear_vector_tests", clear_vector_tests<vector>);
		register_test("pop_back_vector_tests", pop_back_vector_tests<vector>);
		register_test("const_iterators_vector_tests", const_iterators_vector_tests<vector>);
		register_test("assign_vector_tests", assign_vector_tests<vector>);
		register_test("at_vector_tests", at_vector_tests<vector>);
		register_test("erase_vector_tests", erase_vector_tests<vector>);
		register_test("max_size_vector_tests", max_size_vector_tests<vector>);
		register_test("insert_vector", insert_vector<vector>);
	}
	//launch tests
	global.start_test(tests);
}

#endif
