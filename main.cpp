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
	elem2.first = 5;
	elem2.second = 65;
	ft::pair<int, int>	elem3;
	elem3.first = 15;
	elem3.second = -675;
	ft::pair<int, int>	elem4;
	elem4.first = -5;
	elem4.second = 654;

	//mymap.insert(elem);
	mymap.insert(elem);
	mymap.insert(elem2);
	mymap.insert(elem3);
	mymap.insert(elem4);


	/*for (ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end();)
	{
		std::cout << " " << *it++;
	}
	std::cout << std::endl;*/
	ft::map<int, int>::iterator it1 = mymap.end();
	--it1;
	while (it1 != mymap.begin())
	{
		std::cout << " " << (it1--)->second;
	}
  	return 0;
}