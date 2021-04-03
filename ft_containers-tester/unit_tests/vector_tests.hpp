#ifndef VECTOR_TESTS_HPP
# define VECTOR_TESTS_HPP

#include <climits>
# include "../Tester.hpp"

template <class Vector>
void insert_vector() {
	Vector vector;

	vector.push_back(42);
	assert(vector.back() == 42);
	assert(vector.front() == 42);
	vector.push_back(84);
	assert(vector.back() == 84);
	assert(vector.front() == 42);
	assert(vector.size() == 2);
	assert(vector.capacity() == 2);
	vector.insert(vector.begin(), 1);
	assert(vector.front() == 1);

	Vector vector1;
	vector1.push_back(5);
	vector1.push_back(15);
	vector.insert(vector.end(), vector1.begin(), vector1.end());
	assert(vector.size() == 5);
	assert(vector.back() == 15);
	assert(vector[vector.size() - 2] == 5);

	vector.clear();
	assert(vector.size() == 0);
	vector.insert(vector.end(), 5, 42);
	assert(vector.size() == 5);
	for (int i = 0; i < 5; ++i)
	{
		assert(vector[i] == 42);
	}
	vector.clear();
}

template <class Vector>
void capacity_vector_tests() {
	Vector vector;

	assert(vector.empty() == 1);
	assert(vector.capacity() == 0);
	for (int i = 0; i < 14; ++i)
	{ vector.push_back(45); }
	assert(vector.capacity() == 16);
	assert(vector.empty() == 0);
	vector.clear();
	assert(vector.empty() == 1);

	for (int i = 0; i < 50; ++i)
	{ vector.push_back(10); }
	assert(vector.capacity() == 64);
	vector.clear();
	assert(vector.size() == 0);
	assert(vector.capacity() == 64);
}

template <class Vector>
void reserve_vector_tests() {
	Vector vector;

	vector.reserve(1);
	assert(vector.capacity() == 1);
	vector.push_back(42);
	assert(vector.capacity() == 1);
	for (int i = 0; i < 42; ++i)
	{ vector.push_back(789); }
	assert(vector.capacity() == 64);
	vector.reserve(1);
	assert(vector.capacity() == 64);

	Vector vector1;
	vector1.reserve(1);
	assert(vector1.size() == 0);
	assert(vector1.capacity() == 1);
}

template <class Vector>
void iterators_vector_tests() {
	Vector vector;

	vector.push_back(42);
	vector.push_back(54);
	typedef typename Vector::iterator iterator;
	typedef typename Vector::const_iterator const_iterator;
	iterator begin = vector.begin();
	iterator end = vector.end();
	const_iterator cbegin = vector.begin();
	int number = 0;
	while (begin != end) {
		if (number == 0) {
			assert(*begin == 42);
		} else if (number == 1) {
			assert(*begin == 54);
		}
		number++;
		begin++;
		cbegin++;
	}
	assert(number == 2);

	typedef typename Vector::reverse_iterator reverse_iterator;
	reverse_iterator rbegin = vector.rbegin();
	reverse_iterator rend = vector.rend();
	number = 0;
	while (rbegin != rend) {
		if (number == 0) {
			assert(*rbegin == 54);
		} else if (number == 1) {
			assert(*rbegin == 42);
		}
		number++;
		rbegin++;
	}
}

template <class Vector>
void resize_vector_tests() {
	Vector vector;
	vector.resize(42);
	assert(vector.size() == 42);
	for (int i = 0; i < 42; ++i)
	{
		assert(vector[i] == 0);
	}
	vector.resize(1);
	assert(vector.size() == 1);
}

template <class Vector>
void constructors_vector_tests() {
	Vector vector;
	assert(vector.size() == 0);
	assert(vector.capacity() == 0);

	Vector vector1(10, 42);
	assert(vector1.size() == 10);
	assert(vector1.capacity() == 10);

	Vector vector2(vector1.begin(), vector1.end());
	assert(vector2.size() == 10);
	assert(vector2.capacity() == 10);

	Vector vector3(vector2);
	assert(vector3.size() == 10);
	assert(vector3.capacity() == 10);
	assert(*vector3.begin() == 42);
	typedef typename Vector::iterator iterator;
	iterator end = vector3.end();
	end--;
	assert(*end == 42);

	int myints[] = {16,2,77,29};
	Vector fifth (myints, myints + sizeof(myints) / sizeof(int) );
	assert(fifth.size() == 4);
	assert(*fifth.begin() == 16);
}

template <class Vector>
void operators_vector_tests() {
	Vector vector(10, 42);

	Vector vector1 = vector;
	assert(vector1.size() == 10);
	assert(vector1.capacity() == 10);

	Vector vector2(9, 41);
	assert(vector2 < vector);
	assert(vector1 == vector);
	assert(vector1 >= vector);
	assert(vector1 <= vector);
	assert(vector > vector2);

	Vector vector3(10, 41);
	assert(vector3 < vector);
	assert(vector > vector3);
	assert(vector != vector3);
}

template <class Vector>
void assign_vector_tests() {
	Vector vector;
	assert(vector.size() == 0);
	vector.push_back(5);
	assert(vector.size() == 1);
	assert(vector.capacity() == 1);
	vector.assign(2, 50);
	assert(vector.size() == 2);
	assert(vector.capacity() == 2);
	for (int i = 0; i < 5; ++i)
	{
		vector.push_back(i);
	}
	assert(vector.size() == 7);
	assert(vector.capacity() == 8);
	Vector vector1;
	assert(vector1.size() == 0);
	vector1.assign(vector.begin(), vector.end());
	assert(vector1.size() == 7);
	assert(vector1.capacity() == 7);
	typedef typename Vector::iterator iterator;
	iterator begin = vector.begin();
	iterator begin1 = vector1.begin();
	while (begin != vector.end()) {
		assert(*begin == *begin1);
		begin++;
		begin1++;
	}
}

template <class Vector>
void at_vector_tests() {
	Vector vector;
	vector.push_back(42);
	vector.push_back(21);
	assert(vector.at(0) == 42);
	assert(vector.at(1) == 21);
}

template <class Vector>
void erase_vector_tests() {
	Vector vector;

	for (int i = 0; i < 10; ++i)
	{
		vector.push_back(i);
	}
	assert(vector.size() == 10);
	assert(vector.capacity() == 16);
	vector.erase(vector.begin(), vector.end());
	assert(vector.size() == 0);
	for (int i = 0; i < 10; ++i)
	{
		vector.push_back(i);
	}
	assert(vector.size() == 10);
	typedef typename Vector::iterator iterator;
	iterator begin = vector.begin();
	iterator end = vector.end();
	begin++;
	end--;
	vector.erase(begin, end);
	assert(vector.size() == 2);
	assert(*vector.begin() == 0);
	vector.erase(vector.begin());
	assert(vector.size() == 1);
	assert(*vector.begin() == 9);
	vector.erase(vector.begin());
	assert(vector.empty());
}

template <class Vector>
void max_size_vector_tests() {
	Vector vector;

	assert(vector.max_size() > sizeof(size_t));
}

template <class Vector>
void swap_vector_tests() {
	Vector vec(5, 42);
	Vector vec1(8, 21);
	vec.swap(vec1);
	assert(vec.size() == 8);
	assert(vec1.size() == 5);
	for (int i = 0; i < 5; ++i)
	{
		assert(vec1[i] == 42);
	}
	for (int i = 0; i < 8; ++i)
	{
		assert(vec[i] == 21);
	}
}

template <class Vector>
void clear_vector_tests() {
	Vector vector(5, 21);
	assert(vector.size() == 5);
	vector.clear();
	assert(vector.size() == 0);
	assert(vector.capacity() == 5);
}

template <class Vector>
void pop_back_vector_tests() {
	Vector vector;

	vector.push_back(42);
	vector.pop_back();
	assert(vector.size() == 0);
}

template <class Vector>
void element_access_vector_tests() {
	Vector vector;
	vector.push_back(42);
	assert(vector[0] == 42);
	assert(vector.front() == 42);
	assert(vector.back() == 42);
	assert(*(vector.begin()) == 42);
}

template <class Vector>
void const_iterators_vector_tests() {
	typedef typename Vector::iterator iterator;
	typedef typename Vector::const_iterator const_iterator;
	Vector vector;
	vector.push_back(42);
	iterator begin = vector.begin();
	const_iterator cbegin = vector.begin();
	assert(isConst(*begin) == false);
	assert(isConst(*cbegin) == true);
}

#endif