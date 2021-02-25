#include "list.hpp"
#include <list>

int		main(void)
{
	{
		ft::list<int>	l(3, 42);
		std::cout << l.size() << std::endl;
	}
	return (0);
}
