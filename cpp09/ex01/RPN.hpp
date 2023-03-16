#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int print_errmsg(std::string str);

class RPN
{
	public:
	RPN(char *argv)
	{
		std::string str = argv;
		if (!calc(str))
			std::cout << _stack.top() << std::endl;
	}
	~RPN()
	{}
	int get_result()
	{
		return (0);
	}

	private:
	RPN(const RPN &c)
	{
		*this = c;
	}
	RPN &operator=(const RPN &c)
	{
		if (this != &c)
			this->_stack = c._stack;
		return (*this);
	}
	RPN()
	{}

	int calc(std::string str);
	int plus();
	int minus();
	int div();
	int mult();

	std::stack <std::string> _stack;
};

#endif
