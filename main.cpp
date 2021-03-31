#include "list/list.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <list>
#include <vector>
#include <map>
#include <math.h>

#include <iostream>

int main ()
{
	ft::map<int, int> mymap;
	mymap[42] = 12;

	ft::map<int, int>::const_reverse_iterator crit = mymap.rend();

	std::cout << crit->first << std::endl;
	return 0;
}