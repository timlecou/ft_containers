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
	ft::map<int, int>	map;
	//PROBLEME DANS ERASE, LA DEUXIEME MAP BOUCLE INFINI A L'APPEL DU CONSTRUCTEUR
	map.insert(ft::pair<int, int>(42, 12));
	map.insert(ft::pair<int, int>(2, 12));
	map.insert(ft::pair<int, int>(4, 12));
	map.insert(ft::pair<int, int>(432, 12));
	map.insert(ft::pair<int, int>(6543, 12));
	map.insert(ft::pair<int, int>(-5342, 12));

	ft::map<int, int>	map2(map.begin(), map.end());

	for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl;
	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl;
}