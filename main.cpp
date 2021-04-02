










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
  ft::stack<int> st;

  st.push(42);

  ft::stack<int> st1;

  st1.push(2);

  std::cout << (st < st1) << std::endl;
  return 0;
}