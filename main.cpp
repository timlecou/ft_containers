










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
	ft::list<int> mymap(3, 4);

	ft::list<int>::reverse_iterator crit = mymap.rend();

	std::cout << *crit << std::endl;
	return 0;
}