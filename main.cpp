#include "list.hpp"
#include <list>

int		main(void)
{
	ft::list<int>	l;

	l.push_back(42);
	l.push_back(34);
	l.push_back(425);
	l.push_back(4);
	l.push_back(52);
	std::cout << l.back() << std::endl;
	l.push_front(24);
	std::cout << l.front() << std::endl;
	return (0);
}
