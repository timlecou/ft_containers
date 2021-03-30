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
	ft::list<int> mymap(12, 42);

	ft::list<int>::const_reverse_iterator crit = mymap.rbegin();
	return 0;
}