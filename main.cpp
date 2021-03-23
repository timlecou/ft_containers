#include "list/list.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <list>
#include <vector>
#include <map>
#include <math.h>

#include <iostream>

int main () {
	ft::map<int, int> mymap;
	std::map
	ft::pair<int, int>	elem;
	elem.first = 13;
	elem.second = 42;
	mymap.insert(elem);
	ft::pair<int, int>	elem2;
	elem.first = 3;
	elem.second = 46;
	mymap.insert(elem2);
	mymap.display();
  //std::cout << mymap.size() << std::endl;
  return 0;
}