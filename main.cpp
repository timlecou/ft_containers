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
	
	mymap['5'] = 3;

	std::cout << mymap['5'] << std::endl;

	

  	return 0;
}