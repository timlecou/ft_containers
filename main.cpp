#include "list.hpp"
#include "vector.hpp"
#include <list>

int		main(void)
{
	{
		ft::vector<int>	l(0, 42);
		
		std::cout << "back : " << l.back() << std::endl << "size : " << l.size() << std::endl;
		l.push_back(234);
		std::cout << "back : " << l.back() << std::endl << "capacity : " << l.capacity() << std::endl;
		l.pop_back();
		std::cout << "back : " << l.back() << std::endl << "size : " << l.size() << std::endl;
	}
	return (0);
}
