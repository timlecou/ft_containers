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
	ft::pair<int, int>	elem;
	elem.first = 3;
	elem.second = 42;
	ft::pair<int, int>	elem2;
	elem.first = 5;
	elem.second = 65;

	//mymap.insert(elem);
	//mymap.insert(elem);
	mymap.insert(elem2);

	for (ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	{
		std::cout << " salut " << *it;
	}
	std::cout << std::endl;

  	return 0;
}