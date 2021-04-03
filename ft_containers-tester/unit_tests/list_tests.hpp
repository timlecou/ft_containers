#ifndef LIST_TESTS_HPP
# define LIST_TESTS_HPP

# include "../Tester.hpp"

int is_odd(int val)
{
	return (val % 2 == 0);
}

int is_less_than_21(int val)
{
	return (val < 21);
}

int is_upper(int const& lhs, int const& rhs)
{
	return (lhs < rhs);
}

int is_lesser(int const & lhs, int const & rhs)
{
	return (lhs <= rhs);
}

bool sort_desc(const int& first, const int& second)
{
	return (first > second);
}

/*
template<class List>
void template_test()
{
	List list;
}
 */

template<class List>
void swap()
{
	List list;
	list.push_back(42);
	assert(list.size() == 1);

	List list2;
	list2.push_back(12);
	list2.push_back(13);
	assert(list2.size() == 2);

	list.swap(list2);
	assert(list2.size() == 1);
	assert(list.size() == 2);
	assert(list.front() == 12);
	assert(list2.front() == 42);
}

template<class List>
void comparison()
{
	List a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	assert(a.size() == 3);

	List b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	assert(b.size() == 3);

	List c;
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);
	assert(c.size() == 3);

	assert(a == b);
	assert(b != c);
	assert(b < c);
	assert(c > b);
	assert(a <= b);
	assert(a >= b);
}

template<class List>
void splice()
{
	List list;
	list.push_back(42);
	list.push_back(1337);
	assert(list.size() == 2);

	List list2;
	list2.push_back(21);
	list2.push_back(17);
	assert(list2.size() == 2);

	list.splice(list.begin(), list2, list2.begin());
	assert(list.size() == 3);
	list.splice(list.begin(), list2);
	assert(list.size() == 4);
	list.splice(list.begin(), list2, list2.begin(), list2.begin());
	assert(list.size() == 4);
}

template<class List>
void resize()
{
	List list;
	list.push_back(4);
	assert(list.size() == 1);
	list.resize(0);
	assert(list.empty());
	list.resize(42, 100);
	assert(list.size() == 42);
	list.resize(1);
	assert(list.size() == 1);
}

template<class List>
void reverse()
{
	List list;
	for (int i = 0; i < 42; ++i)
	{
		list.push_back(i);
	}
	assert(list.size() == 42);
	assert(list.back() == 41);
	assert(list.front() == 0);
	list.reverse();
	assert(list.front() == 41);
	assert(list.back() == 0);
	list.clear();
	list.reverse();
}

template<class List>
void sort()
{
	List list;
	list.push_back(2);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(1);
	list.push_back(0);
	list.push_back(4);
	assert(list.size() == 7);
	list.sort();
	assert(list.front() == 0);
	assert(list.back() == 8);
	list.sort(sort_desc);
	assert(list.front() == 8);
	assert(list.back() == 0);
}

template<class List>
void merge()
{
	List list;
	list.push_back(5);
	list.push_back(7);
	assert(list.size() == 2);
	List list2;
	list2.push_back(0);
	list2.push_back(3);
	assert(list2.size() == 2);
	list.merge(list2, is_lesser);
	assert(list2.empty());
	assert(list.size() == 4);
	assert(list.back() == 7);
	assert(list.front() == 0);
}

template<class List>
void pop_back() {
	List list;
	list.push_back(42);
	list.push_front(21);
	assert(list.size() == 2);
	list.pop_back();
	assert(list.size() == 1);
	list.pop_back();
	assert(list.size() == 0);
}

template<class List>
void unique_binary_pred()
{
	List list;
	for (int i = 0; i < 10; ++i)
	{
		list.push_back(i);
		list.push_back(i);
	}
	assert(list.size() == 20);
	list.unique(is_upper);
	assert(list.size() == 2);
}

template<class List>
void unique()
{
	List list;
	for (int i = 0; i < 10; ++i)
	{
		list.push_back(i);
		list.push_back(i);
	}
	assert(list.size() == 20);
	list.unique();
	assert(list.size() == 10);
}

template<class List>
void const_values_list_tests() {
	List list;

	list.push_back(42);
	typedef typename List::iterator iterator;
	typedef typename List::const_iterator const_iterator;
	iterator begin = list.begin();
	const_iterator cbegin = list.begin();
	assert(isConst(*begin) == false);
	assert(isConst(*cbegin));
}

template <class List>
void constructors_list() {
	typedef typename List::iterator iterator;
//	typedef typename List::const_iterator const_iterator;

	List list;
	assert(list.size() == 0);

	List list1(5, 42);
	assert(list1.size() == 5);
	iterator begin = list1.begin();
	while (begin != list1.end()) {
		assert(*begin == 42);
		begin++;
	}

	List list2(list1);
	assert(list2.size() == 5);
	begin = list2.begin();
	while (begin != list2.end()) {
		assert(*begin == 42);
		begin++;
	}

	List list3(list2.begin(), list2.end());
	assert(list3.size() == 5);
	begin = list3.begin();
	while (begin != list3.end()) {
		assert(*begin == 42);
		begin++;
	}
}

template<class List>
void remove_if()
{
	typedef typename List::iterator iterator;
	List list;
	for (int i = 0; i < 42; ++i)
	{
		list.push_back(i);
	}
	list.remove_if(is_odd);
	list.remove_if(is_less_than_21);
	iterator begin = list.begin();
	while (begin != list.end())
	{
		assert(*begin % 2 != 0);
		assert(*begin >= 21);
		begin++;
	}
}

template<class List>
void remove()
{
	List list;
	for (int i = 0; i < 42; ++i)
	{
		list.push_back(i);
	}
	list.remove(23);
	assert(list.size() == 41);
	list.remove(56);
	assert(list.size() == 41);
	assert(list.back() == 41);
	for (int i = 0; i < 42; ++i)
	{
		list.remove(i);
	}
	assert(list.size() == 0);
}

template<class List>
void insert()
{
	List list;
	list.insert(list.begin(), 5);
	assert(*list.begin() == 5);
	assert(list.size() == 1);
	list.clear();
	list.insert(list.begin(), 5, 64);
	assert(list.front() == 64);
	assert(list.back() == 64);
	assert(list.size() == 5);
	list.clear();
	List list2;
	list2.assign(4, 32);
	list.insert(list.begin(), list2.begin(), list2.end());
	assert(list.size() == list2.size());
	assert(list.front() == list2.front());
	assert(list.back() == list2.back());
}

template<class List>
void assign()
{
	List list;
	list.assign(3, 42);
	assert(list.size() == 3);
	list.clear();
	List list2;
	list2.assign(5, 90);
	list.assign(list2.begin(), list2.end());
	assert(list.size() == list2.size());
	assert(list.begin() != list2.begin());
}

template<class List>
void erase()
{
	typedef typename List::iterator iterator;
	List list;
	list.push_back(42);
	list.erase(list.begin(), list.end());
	assert(list.size() == 0);
	list.push_front(41);
	list.push_front(42);
	list.push_front(43);
	assert(list.front() == 43);
	assert(list.back() == 41);
	iterator begin = list.begin();
	begin++;
	list.erase(begin, list.end());
	assert(list.size() == 1);
	list.erase(list.begin());
	assert(list.size() == 0);
	list.push_back(42);
	assert(list.back() == 42);
	iterator end = list.end();
	--end;
	list.erase(end);
	assert(list.size() == 0);
}

template<class List>
void empty_and_size()
{
	List list;
	for (size_t i = 0; i < 60; ++i)
	{
		list.push_back(i / 3);
	}
	list.clear();
	assert(list.empty() == 1);
	assert(list.size() == 0);
}

template<class List>
void iterators()
{
	typedef typename List::iterator iterator;
	typedef typename List::const_iterator const_iterator;
	List list;
	list.push_back(42);
	list.push_front(5);
	assert(list.size() == 2);
	iterator begin = list.begin();
	const_iterator cbegin = list.begin();
	assert(isConst(*begin) == false);
	assert(isConst(*cbegin) == true);
	assert(*begin == 5);
	assert(*cbegin == 5);
	begin++;
	cbegin++;
	assert(*begin == 42);
	assert(*cbegin == 42);
	iterator end = list.end();
	const_iterator cend = list.end();
	end--;
	cend--;
	assert(*end == 42);
	assert(*cend == 42);
	end--;
	cend--;
	assert(*end == 5);
	assert(*cend == 5);
	assert(end == list.begin());
	assert(cend == list.begin());
}

template<class List>
void reverse_iterators()
{
	typedef typename List::reverse_iterator reverse_iterator;
	List list;
	list.push_back(42);
	list.push_front(5);
	assert(list.size() == 2);
	reverse_iterator rend = list.rend();
	rend++;
	assert(*rend == 42);
	rend++;
	assert(*rend == 5);
}

template<class List>
void front_back()
{
	List list;
	list.push_back(42);
	list.push_front(5);
	assert(list.size() == 2);
	assert(list.front() == 5);
	assert(*list.begin() == 5);
	assert(list.back() == 42);
}

template<class List>
void empty_list()
{
	List empty;
	assert(empty.size() == 0);
}

template<class List>
void push_back_one_element()
{
	List empty;
	empty.push_back(42);
	assert(empty.size() == 1);
}

template<class List>
void push_front_one_element()
{
	List empty;
	empty.push_front(42);
	assert(empty.size() == 1);
}

template<class List>
void forty_two_elements_push_back_front()
{
	List empty;
	for (int i = 0; i < 42; ++i)
	{
		if (i % 2 == 0)
			empty.push_front(42);
		else
			empty.push_back(42);
	}
	assert(empty.size() == 42);
}



#endif