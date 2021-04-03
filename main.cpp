










#include "list/list.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <list>
#include <vector>
#include <map>
#include <math.h>

#include <iostream>

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m3["a"] = 1;
	m3["b"] = 42;
	m3["c"] = 42;
	m3["d"] = 42;
	m3 = m1;
	m4 = m2;
	m1["e"] = 1;
	m2["e"] = 1;
	m3["e"] = 3;
	m4["e"] = 3;

	std::cout << (m1 == m3) << std::endl;
	std::cout << (m2 == m4) << std::endl;
	return 0;
}