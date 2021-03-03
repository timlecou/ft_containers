#include "list.hpp"
#include "vector.hpp"
#include <list>
#include <vector>

int		main(void)
{
	ft::vector<int> v;

	v.push_back(42);

	ft::vector<int>::const_iterator	it = v.begin();
	std::cout << "test" << std::endl;

	std::cout << *it << std::endl;
	return (0);
}
