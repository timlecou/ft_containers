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
	map.insert(ft::pair<int, int>(4, 12));
	map.insert(ft::pair<int, int>(2, 12));
	map.insert(ft::pair<int, int>(6, 12));
	map.insert(ft::pair<int, int>(1, 12));
	map.insert(ft::pair<int, int>(3, 12));
	map.insert(ft::pair<int, int>(5, 12));
	map.insert(ft::pair<int, int>(7, 12));

	for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl;

	map.erase(map.begin(), map.end());

	/*ft::map<int, int>::iterator	it = map.begin();
	std::cout << "begin() = " << map.begin()->first << std::endl;

	it++;
	it++;
	map.erase(it);

	for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl;*/
  return (0);
}