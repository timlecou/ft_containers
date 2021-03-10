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
	// ? 9 8 7 6 5 4 3 2 1 0 ?
	iter_type from (myvector.begin());                     //   ^
	//         ------>
	iter_type until (myvector.end());                      //                       ^
	//
	ft::reverse_iterator<iter_type> rev_until (from);     // ^
	//         <------
	ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';

	return 0;
}
