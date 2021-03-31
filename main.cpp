










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
	ft::map<int, int> ma;

	ma[45] = 32;
	ma[21] = 45;

	ft::map<int, int>::const_iterator it = ma.begin();

	std::cout << it->first << " - " << it->second << std::endl;
	it++;
	std::cout << it->first << " - " << it->second << std::endl;
	return 0;
}