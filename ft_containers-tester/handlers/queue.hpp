#ifndef HANDLER_QUEUE_HPP
# define HANDLER_QUEUE_HPP

#include <map>
# include "../Tester.hpp"
# include "../unit_tests/queue_tests.hpp"

template<class Vector>
void exec_test_queue(wanted_tests_type tests = wanted_tests_type())
{
	new_type("Queue");
	{
		//register tests
		register_test("constructor_queue_tests", constructor_queue_tests<Vector>);
		register_test("empty_queue_tests", empty_queue_tests<Vector>);
		register_test("size_queue_tests", size_queue_tests<Vector>);
		register_test("accessors_queue_tests", accessors_queue_tests<Vector>);
		register_test("push_queue_tests", push_queue_tests<Vector>);
		register_test("pop_queue_tests", pop_queue_tests<Vector>);
		register_test("operators_queue_tests", operators_queue_tests<Vector>);

	}
	//launch tests
	global.start_test(tests);
}

#endif