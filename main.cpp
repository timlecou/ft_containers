










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
	ft::map<std::string, int> m1;

	m1["salut"] = 42;

	ft::map<std::string, int> m2(m1);
	return 0;
}
