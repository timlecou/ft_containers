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
  ft::map<int,int> mymap;

  mymap[42] = 45;
  mymap[45] = 25;

  mymap.erase(42);
  mymap.erase(42);

  mymap[0]=12;
  mymap[-1]=24;

  mymap.erase(mymap.begin(), mymap.end());
  //std::cout << mymap.size() << std::endl;
  return 0;
}