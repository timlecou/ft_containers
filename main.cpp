#include "list/list.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <list>
#include <vector>
#include <map>
#include <math.h>

#include <iostream>     // std::cout

int main () {
	ft::map<int, int> mymap;
  ft::map<int, int> mymap2(mymap);


  std::cout << mymap2.max_size() << std::endl;
  return 0;
}