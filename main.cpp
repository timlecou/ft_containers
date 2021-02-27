#include "list.hpp"
#include "vector.hpp"
#include <list>

int		main(void)
{
	{
		ft::vector<int>	l(3, 42);
		
		l.push_back(234);
		std::cout << l.back() << std::endl;
	}
	return (0);
}
