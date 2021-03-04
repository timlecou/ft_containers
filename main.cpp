#include "list.hpp"
#include "vector.hpp"
#include <list>

int		main(void)
{
	std::list<int> v;
	int		tmp = 34;

	v.push_back(42);
	v.push_back(2);
	v.push_back(21);

	//std::list<int>::iterator	it = v.begin();

	std::cout << v.front() << std::endl;
	//++it;
	//std::cout << *it << std::endl;
	return (0);
}
