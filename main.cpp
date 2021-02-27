#include "list.hpp"
#include "vector.hpp"
#include <list>

int		main(void)
{
	{
		ft::vector<int>	l(0, 42);

		l.push_back(42);
		l.resize(10);
		ft::vector<int>::iterator	it = l.begin();
		for (ft::vector<int>::iterator ite = l.end(); it != ite ; it++)
			std::cout << *it << "  " << std::endl;
	}
	return (0);
}
