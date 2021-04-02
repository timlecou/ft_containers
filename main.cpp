










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
	std::list<double> first, second, third;

	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	third.push_back(3.7);
	third.push_back(7.1);
	third.push_back(1.4);

	first.sort();
	second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back(2.1);

	first.merge(second, mycomparison);

	first.merge(third);

	std::cout << "first contains:";
	for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}