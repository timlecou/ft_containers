#include "list.hpp"
#include "vector.hpp"

int		main(void)
{
	ft::list<int> v;

	v.push_back(42);

	ft::list<int>::iterator	it = v.begin();

	std::cout << *it << std::endl;
	return (0);
}
