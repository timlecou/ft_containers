#include "list.hpp"
#include "vector.hpp"
#include <list>
#include <vector>

int		main(void)
{
	{
		std::vector<int>	l(1, 42);
		std::vector<int>::iterator test = l.begin();




		l.push_back(420);
		l.push_back(540);
		l.push_back(42065);
		l.push_back(40);
		l.push_back(4);
		l.push_back(2065);

		test += 4;

		std::cout << "test : " << *test << std::endl;

		//l.resize(12);
		l.insert(test, 34500000);
		std::vector<int>::iterator	it = l.begin();
		for (std::vector<int>::iterator ite = l.end(); it != ite ; it++)
			std::cout << *it << "  " << std::endl;
		std::cout << "size = " << l.size() << std::endl;
	}
	return (0);
}
