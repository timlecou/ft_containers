#include "list.hpp"
#include "vector.hpp"
#include <list>
#include <vector>
#include <math.h>

int main ()
{
  // constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  std::cout << "1" << std::endl;
  ft::vector<int> second (4,100);                       // four ints with value 100
  std::cout << "2" << std::endl;
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  std::cout << "3" << std::endl;
  ft::vector<int> fourth (third);                       // a copy of third
  std::cout << "4" << std::endl;

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
