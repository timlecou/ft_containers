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

	ft::pair<int, int>	elem;
	elem.first = 3;
	elem.second = 42;
	mymap.insert(elem);
	mymap.insert(elem);
  std::cout << mymap.size() << std::endl;
  return 0;
}