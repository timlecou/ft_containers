










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
  ft::map<int, int>	var;

  var[1] =  42;
  var[2] =  45;
  var[45] =  65;
  var[3] =  74;
  var.erase(var.begin(), var.end());
  var[1] =  42;
  var[2] =  45;
  var[45] =  65;
  var[3] =  74;
  ft::map<int, int>::iterator   it = var.begin();

  it++;
  var.erase(it,var.end());

  std::cout << var.size() << std::endl;
  
  return 0;
}