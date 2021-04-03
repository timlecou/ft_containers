#ifndef HANDLER_STACK_HPP
# define HANDLER_STACK_HPP

#include <map>
# include "../Tester.hpp"
# include "../unit_tests/stack_tests.hpp"

template<class Stack>
void exec_test_stack(wanted_tests_type tests = wanted_tests_type())
{
	new_type("Stack");
	{
		//register tests
		register_test("constructor_stack_tests", constructor_stack_tests<Stack>);
		register_test("empty_stack_tests", empty_stack_tests<Stack>);
		register_test("size_stack_tests", size_stack_tests<Stack>);
		register_test("top_stack_tests", top_stack_tests<Stack>);
		register_test("push_stack_tests", push_stack_tests<Stack>);
		register_test("pop_stack_tests", pop_stack_tests<Stack>);
		register_test("operators_stack_tests", operators_stack_tests<Stack>);
	}
	//launch tests
	global.start_test(tests);
}

#endif