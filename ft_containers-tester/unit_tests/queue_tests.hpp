#ifndef QUEUE_TESTS_HPP
# define QUEUE_TESTS_HPP

#include <climits>
# include "../Tester.hpp"

template <class Queue>
void constructor_queue_tests() {
	Queue queue;
	assert(queue.empty());
	assert(queue.size() == 0);
	queue.push(42);
	assert(queue.size() == 1);
}

template <class Queue>
void empty_queue_tests() {
	Queue queue;
	assert(queue.empty());
	queue.push(12);
	assert(!queue.empty());
}

template <class Queue>
void size_queue_tests() {
	Queue queue;
	for (int i = 0; i < 10; ++i)
	{
		queue.push(i);
	}
	assert(queue.size() == 10);
}

template <class Queue>
void accessors_queue_tests() {
	Queue queue;
	queue.push(42);
	queue.push(52);
	assert(queue.front() == 42);
	assert(queue.back() == 52);
}

template <class Queue>
void push_queue_tests() {
	Queue queue;
	queue.push(-456456);
	queue.push(4562);
	assert(queue.front() == -456456);
	assert(queue.back() == 4562);
	assert(queue.size() == 2);
}

template <class Queue>
void pop_queue_tests() {
	Queue queue;
	queue.push(22);
	queue.pop();
	assert(queue.size() == 0);
}

template <class Queue>
void operators_queue_tests() {
	Queue queue;
	queue.push(42);
	Queue queue1;
	queue1.push(41);
	Queue queue2;
	queue2.push(42);
	queue2.push(42);

	assert(queue == queue);
	assert(queue < queue2);
	assert(queue1 < queue);
	assert(queue1 < queue2);
	assert(queue <= queue);
	assert(queue2 > queue1);
}

#endif