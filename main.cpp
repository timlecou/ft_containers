










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
  ft::vector<int> v1;
	ft::vector<int> v3;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v3 = v1;
	std::cout << (v1 > v3) << std::endl;
  std::cout << (v1 < v3) << std::endl;
	v1.push_back(42);
  std::cout << (v1 > v3) << std::endl;
  std::cout << (v1 < v3) << std::endl;
  return 0;
}