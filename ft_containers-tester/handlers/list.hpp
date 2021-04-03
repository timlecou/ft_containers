#ifndef HANDLER_LIST_HPP
# define HANDLER_LIST_HPP

#include <map>
# include "../Tester.hpp"
# include "../unit_tests/list_tests.hpp"

template<class List>
void exec_test_list(wanted_tests_type tests = wanted_tests_type())
{
	new_type("List");
	{
		//register tests
		register_test("empty_list", empty_list<List>);
		register_test("push_back_one_element", push_back_one_element<List>);
		register_test("push_front_one_element", push_front_one_element<List>);
		register_test("forty_two_elements_front_back", forty_two_elements_push_back_front<List>);
		register_test("front_back", front_back<List>);
		register_test("iterators", iterators<List>);
		register_test("reverse_iterators", reverse_iterators<List>);
		register_test("empty_and_size", empty_and_size<List>);
		register_test("erase", erase<List>);
		register_test("insert", insert<List>);
		register_test("remove", remove<List>);
		register_test("remove_if", remove_if<List>);
		register_test("unique", unique<List>);
		register_test("unique_binary_pred", unique_binary_pred<List>);
		register_test("merge", merge<List>);
		register_test("sort", sort<List>);
		register_test("reverse", reverse<List>);
		register_test("resize", resize<List>);
		register_test("splice", splice<List>);
		register_test("comparison", comparison<List>);
		register_test("const_values_list_tests", const_values_list_tests<List>);
		register_test("pop_back", pop_back<List>);
		register_test("swap", swap<List>);
		register_test("constructors_list", constructors_list<List>);
	}
	//launch tests
	global.start_test(tests);
}

#endif