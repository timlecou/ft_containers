










#include "list/list.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <list>
#include <vector>
#include <map>
#include <math.h>

#include <iostream>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  std::map<int, int>	var;

  var[3] =  42;

  std::map<int, int>	var2;

  var2[2] = 41;
  var2[1] = 12;

  std::cout << (var < var2) << std::endl;
  
  return 0;
}