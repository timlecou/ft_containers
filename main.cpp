#include "list.hpp"
#include "vector.hpp"
#include <list>
#include <vector>
#include <math.h>

int main ()
{
  ft::vector<int>	vec(4, 42);
  ft::vector<int>::iterator	it = vec.begin();

  *it = 5;
  return 0;
}
