#include "list/list.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include <list>
#include <vector>
#include <math.h>

#include <iostream>     // std::cout

int main () {
	ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  return 0;
}
