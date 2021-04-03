#ifndef STACK_TESTS_HPP
# define STACK_TESTS_HPP

#include <climits>
# include "../Tester.hpp"

template <class Stack>
void constructor_stack_tests() {
	Stack stack;
	stack.push(42);
	assert(stack.size() == 1);
	assert(stack.top() == 42);
}

template <class Stack>
void empty_stack_tests() {
	Stack stack;
	assert(stack.empty());
	stack.push(22);
	assert(stack.empty() == false);
}

template <class Stack>
void size_stack_tests() {
	Stack stack;
	assert(stack.size() == 0);
	for (int i = 0; i < 12; ++i)
	{
		stack.push(i);
	}
	assert(stack.size() == 12);
}

template <class Stack>
void top_stack_tests() {
	Stack stack;
	for (int i = 0; i < 5; ++i)
	{
		stack.push(i * 5);
	}
	assert(stack.top() == 20);
}

template <class Stack>
void push_stack_tests() {
	Stack stack;
	assert(stack.size() == 0);
	stack.push(22);
	assert(stack.size() == 1);
	assert(stack.top() == 22);
}

template <class Stack>
void pop_stack_tests() {
	Stack stack;
	stack.push(42);
	assert(stack.size() == 1);
	stack.pop();
	assert(stack.size() == 0);
}

template <class Stack>
void operators_stack_tests() {
	Stack stack;
	Stack stack1;
	assert(stack == stack1);
	assert(stack <= stack1);
	assert(stack >= stack1);
	stack.push(21);
	assert(stack > stack1);
	assert(stack1 < stack);
	stack1.push(22);
	assert(stack1 > stack);
	assert(stack < stack1);
}


#endif