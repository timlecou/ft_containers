










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
	ft::map<int, int> ma;

	ma[45] = 32;
	ma[21] = 45;

	ft::map<int, int> ma2;

	ma2[1] = 2;
	ma2[2] = 3;

	for (ft::map<int, int>::iterator it = ma.begin(); it != ma.end(); it++)
		std::cout << " " << it->first << ": " << it->second;
	std::cout << std::endl;
	for (ft::map<int, int>::iterator it = ma2.begin(); it != ma2.end(); it++)
		std::cout << " " << it->first << ": " << it->second;
	std::cout << std::endl;

	ma.swap(ma2);

	for (ft::map<int, int>::iterator it = ma.begin(); it != ma.end(); it++)
		std::cout << " " << it->first << ": " << it->second;
	std::cout << std::endl;
	for (ft::map<int, int>::iterator it = ma2.begin(); it != ma2.end(); it++)
		std::cout << " " << it->first << ": " << it->second;
	std::cout << std::endl;
	return 0;
}