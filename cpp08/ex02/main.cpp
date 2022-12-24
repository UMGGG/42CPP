#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;  // 17
	mstack.pop(); // -17
	std::cout << mstack.size() << std::endl; // 1
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it; // -> 3
	--it; // -> 5
	while (it != ite)
	{
		std::cout << *it << std::endl; // 5 3 5 737
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	MutantStack<char> my_stack;

	my_stack.push('a');
	my_stack.push('b');
	my_stack.push('c');

	MutantStack<char>::iterator my_iter_begin = my_stack.begin();
	MutantStack<char>::iterator my_iter_end = my_stack.end();

	std::list<char> my_list(my_iter_begin, my_iter_end);
	std::list<char>::iterator my_list_begin = my_list.begin();
	std::list<char>::iterator my_list_end = my_list.end();

	for (; my_iter_begin != my_iter_end; my_iter_begin++)
	{
		std::cout << "mutantstack : " << *my_iter_begin << std::endl;
	}

	for (; my_list_begin != my_list_end; my_list_begin++)
	{
		std::cout << "list : " << *my_list_begin << std::endl;
	}
	std::cout << "----------reverse-----------------" << std::endl;
	MutantStack<char>::reverse_iterator my_iter_rbegin = my_stack.rbegin();
	MutantStack<char>::reverse_iterator my_iter_rend = my_stack.rend();

	std::list<char>::reverse_iterator my_list_rbegin = my_list.rbegin();
	std::list<char>::reverse_iterator my_list_rend = my_list.rend();

	for (; my_iter_rbegin != my_iter_rend; my_iter_rbegin++)
	{
		std::cout << "mutantstack : "<< *my_iter_rbegin << std::endl;
	}

	for (; my_list_rbegin != my_list_rend; my_list_rbegin++)
	{
		std::cout << "list : "<< *my_list_rbegin << std::endl;
	}
	return 0;
}
