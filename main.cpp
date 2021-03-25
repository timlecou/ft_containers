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
	
	mymap['1'] = 3;
	mymap['2'] = 42;
	mymap['3'] = 12;


	for (ft::map<char, int>::iterator it1 = mymap.begin(); it1 != mymap.end(); it1++)
		std::cout << "first: " << it1->first << std::endl;

	mymap.clear();

	for (ft::map<char, int>::iterator it1 = mymap.begin(); it1 != mymap.end(); it1++)
	{
		std::cout << "second: " << it1->first << std::endl;
	}

  	return 0;
}