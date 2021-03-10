#include "list.hpp"
#include "vector.hpp"
#include <list>
#include <vector>
#include <math.h>

#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector

int main () {
  ft::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  typedef ft::vector<int>::iterator iter_type;

  ft::reverse_iterator<iter_type> rev_end (myvector.begin());
  ft::reverse_iterator<iter_type> rev_begin (myvector.end());

  std::cout << "myvector:";
  for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
