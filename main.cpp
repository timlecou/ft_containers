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
	ft::map<char, int> mymap;
	
	ft::pair<char, int>	e;
	e.first = '1';
	e.second = 42;

	mymap.insert(e);

	std::cout << mymap.count('1') << std::endl;

	

  	return 0;
}