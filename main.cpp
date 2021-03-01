#include "list.hpp"
#include "vector.hpp"
#include <list>
#include <vector>

int		main(void)
{
	{
	/*	ft::vector<int>	l(1, 42);




		l.push_back(420);
		l.push_back(540);
		l.push_back(42065);
		l.push_back(40);
		l.push_back(4);
		l.push_back(2065);

		ft::vector<int>::iterator test = l.begin();
		test++;
		test++;
		test++;

		std::cout << "size : " << l.size() << std::endl;
		ft::vector<int>::iterator	ita = l.begin();
		for (ft::vector<int>::iterator itb = l.end(); ita != itb ; ita++)
			std::cout << *ita << "  " << std::endl;
		std::cout << "------------" << std::endl;
		//l.insert(test, 3, 3333);
		l.erase(l.begin() + 1, l.end() - 2);
		std::cout << "size : " << l.size() << std::endl;
		ft::vector<int>::iterator	it = l.begin();
		for (ft::vector<int>::iterator ite = l.end(); it != ite ; it++)
			std::cout << *it << "  " << std::endl;
		std::cout << "size = " << l.size() << std::endl;*/



		ft::vector<int> foo (3,100);   // three ints with a value of 100
  		ft::vector<int> bar (5,200);   // five ints with a value of 200

  		foo.swap(bar);

  		std::cout << "foo contains:";
  		for (unsigned i=0; i<foo.size(); i++)
    		std::cout << ' ' << foo[i];
  		std::cout << '\n';

  		std::cout << "bar contains:";
  		for (unsigned i=0; i<bar.size(); i++)
    		std::cout << ' ' << bar[i];
  		std::cout << '\n';

	}
	return (0);
}
