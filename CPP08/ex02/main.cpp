#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
	std::cout << "make stack\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << "\nprint iteration\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nprint copy stack\n";
	std::stack<int> s(mstack);
	while (s.size() > 0)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\nprint assigned mutantstack\n";
	MutantStack<int> ms;
	ms = mstack;

	MutantStack<int>::iterator ita = mstack.begin();
	MutantStack<int>::iterator itea = mstack.end();

	while (ita != itea)
	{
		std::cout << *ita << std::endl;
		++ita;
	}

	return 0;
}
