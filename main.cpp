#include "list.hpp"
#include <list>

int		main(void)
{
	{
	ft::list<int>	l;

	l.push_back(2);
	l.push_back(34);
	l.push_back(425);
	l.push_back(4);
	l.push_back(52);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.back() << std::endl;
	}

	{
	//string
	ft::list<std::string>	l;

	l.push_back("salut");
	l.push_back("je");
	l.push_back("suis");
	l.push_back("tim");
	std::cout << l.front() << std::endl;
	std::cout << l.back() << std::endl;
	l.pop_back();
	l.pop_front();
	std::cout << l.front() << std::endl;
	std::cout << l.back() << std::endl;
	}
	return (0);
}
