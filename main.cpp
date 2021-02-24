#include "list.hpp"

int		main(void)
{
	ft::list<int>	l(3, 4);

	std::cout << l.size() << std::endl;
	return (0);
}
