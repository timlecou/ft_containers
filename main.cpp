#include "list.hpp"
#include "vector.hpp"
#include <list>

int		main(void)
{
	{
		ft::vector<int>	l(0, 42);

		l.push_back(42);
		l.push_back(22);
		ft::vector<int>::iterator	begin = l.begin();
		ft::vector<int>::iterator	begin2 = l.begin();
		if (begin == begin2)
			std::cout << "*begin : " << begin[0] << std::endl;
		begin++;
		std::cout << "*begin : " << begin[0] << std::endl;
	}
	return (0);
}
