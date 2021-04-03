#ifndef MAP_TESTS_HPP
# define MAP_TESTS_HPP

# include "../Tester.hpp"

template<class Map>
void insert_and_change_values()
{
	Map map;
	assert(map.size() == 0);
	map[0] = 42;
	assert(map[0] == 42);
	map[0] = 21;
	assert(map[0] == 21);
	assert(map.size() == 1);
	map[1000] = 21;
	assert(map.size() == 2);
}

template<class Map>
void const_values_test()
{
	Map map;

	map[0] = 42;
	typedef typename Map::iterator iterator;
	typedef typename Map::const_iterator const_iterator;
	iterator begin = map.begin();
	const_iterator cbegin = map.begin();
	assert(isConst(begin->first));
	assert(isConst(begin->second) == false);
	assert(isConst(cbegin->first));
	assert(isConst(cbegin->second));
}

template<class Map>
void constructors()
{
	Map map1;
	map1[0] = 42;
	assert(map1[0] == 42);
	assert(map1.size() == 1);
	Map map2(map1);
	assert(map2[0] == 42);
	assert(map2.size() == 1);
	map2[1] = 56;
	map2[2] = 765;
	Map map3(map2.begin(), map2.end());
	assert(map3[0] == 42);
	assert(map3[1] == 56);
	assert(map3.size() == 3);
}

template<class Map>
void operators()
{
	Map map;
	map[0] = 42;
	Map map1 = map;
	assert(map1[0] == 42);
	assert(map1 == map);
	assert(map1 >= map);
	assert(map1 <= map);
	assert((map1 < map) == false);
	assert((map1 > map) == false);
	map1[0] = 21;
	assert(map1 != map);
	assert(map1 < map);
	assert((map1 > map) == false);
	assert((map1 >= map) == false);
	assert(map1 <= map);
	map[0] = 45;
	assert(map > map1);
}

template<class Map>
void iterators_tests()
{
	Map map;
	map[45] = 32;
	map[21] = 45;
	typedef typename Map::iterator iterator;
	typedef typename Map::const_iterator const_iterator;
	typedef typename Map::reverse_iterator reverse_iterator;
	typedef typename Map::const_reverse_iterator const_reverse_iterator;
	iterator begin = map.begin();
	assert(begin->first == 21 && begin->second == 45);
	begin++;
	assert(begin->first == 45 && begin->second == 32);
	const_iterator cbegin = map.begin();
	assert(cbegin->first == 21 && cbegin->second == 45);
	cbegin++;
	assert(cbegin->first == 45 && cbegin->second == 32);
	reverse_iterator rbegin = map.rbegin();
	assert(rbegin->first == 45 && rbegin->second == 32);
	rbegin++;
	assert(rbegin->first == 21 && rbegin->second == 45);
	const_reverse_iterator crbegin = map.rbegin();
	assert(crbegin->first == 45 && crbegin->second == 32);
	crbegin++;
	assert(crbegin->first == 21 && crbegin->second == 45);
}

template<class Map>
void capacity_tests()
{
	Map map;
	assert(map.empty());
	assert(map.size() == 0);
	map[0] = 1;
	assert(!map.empty());
	assert(map.size() == 1);
}

template<class Map>
void erase_test()
{
	Map map;
	map[42] = 45;
	map[45] = 25;
	size_t ret = map.erase(42);
	assert(map.size() == 1);
	assert(ret == 1);
	ret = map.erase(42);
	assert(ret == 0);
	Map map1 = map;
	assert(map1.size() == 1);
	assert(map1[45] == 25);
	assert(map1[42] == 0);
	map[1] = 2;
	map[-1] = 3;
	map.erase(map.begin(), map.end());
	assert(map.size() == 0);
	assert(map1.size() == 2);
	map1.erase(map1.begin());
	assert(map1.size() == 1);
	assert(map1.begin()->first == 45);
	map1.erase(map1.begin());
	assert(map1.size() == 0);
	map.clear();
	map[1] = 42;
	map[2] = 45;
	map[45] = 65;
	map[3] = 74;
	assert(map.size() == 4);
	typedef typename Map::iterator iterator;
	iterator begin = map.begin();
	begin++;
	map.erase(begin, map.end());
	assert(map.size() == 1);
	assert(map.begin()->second == 42);
}

template<class Map>
void swap_test()
{
	Map map;
	map[0] = 42;
	map[1] = 21;
	Map map1;
	map1[0] = 23;
	map.swap(map1);
	assert(map[0] == 23);
	assert(map.size() == 1);
	assert(map1[0] == 42);
	assert(map1.size() == 2);
}

template<class Map>
void find_tests()
{
	typedef typename Map::iterator iterator;
	typedef typename Map::const_iterator const_iterator;
	Map map;
	map[0] = 12;
	map[1] = 24;
	iterator found = map.find(0);
	const_iterator cfound = map.find(0);
	assert(found != map.end());
	assert(cfound != map.end());
	found = map.find(43543);
	cfound = map.find(43543);
	assert(found == map.end());
	assert(cfound == map.end());
}

template<class Map>
void bounds_tests()
{
	typedef typename Map::iterator iterator;
	typedef typename Map::const_iterator const_iterator;
	Map map;
	for (int i = 0; i < 10; ++i)
	{
		map[i] = i * 5;
	}
	iterator lb = map.lower_bound(5);
	iterator ub = map.upper_bound(5);
	const_iterator clb = map.lower_bound(5);
	const_iterator cub = map.upper_bound(5);
	ft::pair<iterator, iterator> er = map.equal_range(5);
	ft::pair<const_iterator, const_iterator> cer = map.equal_range(5);
	assert(lb->second == 25);
	assert(clb->second == 25);
	assert(ub->second == 30);
	assert(cub->second == 30);
	assert(er.first->second == 25);
	assert(cer.first->second == 25);
	assert(er.second->second == 30);
	assert(cer.second->second == 30);
}

template<class Map>
void count_test() {
	Map map;

	map[50] = 42;
	map[12] = 785;
	assert(map.count(50) == 1);
	assert(map.count(12) == 1);
	map.erase(12);
	assert(map.count(0) == 0);
}

template<class Map>
void insert_test()
{
	Map map;
	map.insert(ft::pair<int, int>(0, 40));
	map.insert(ft::pair<int, int>(0, 50));
	assert(map.size() == 1);
	assert(map[0] == 40);
	map[43] = 21;
	map[7] = 3;
	map[3] = 3;
	assert(map.size() == 4);
	typename Map::iterator begin = map.begin();
	begin++;
	map.insert(begin, ft::pair<int, int>(42, 42));
	Map map2;
	map2.insert(map.begin(), map.end());
	assert(map2.size() == 5);
}

#endif