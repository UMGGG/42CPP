#include "RPN.hpp"

int print_errmsg(std::string str)
{
	std::cout << "error: " << str << std::endl;
	return (1);
}

int string_to_int(std::string str)
{
	int num = 0;
	int sign = 1;
	size_t i = 0;

	if (str[0] == '-')
	{
		if (str.size() == 1)
			return (-1);
		sign = -1;
		i++;
	}
	for (; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			num = num * 10 + (str[i] - '0');
		}
		else
			return (-1);
	}
	return num * sign;
}

std::string int_to_string(int num)
{
	char digit;
	if (num == 0)
		return "0";
	std::string str = "";
	int isNegative = 0;
	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	while (num > 0)
	{
		digit = '0' + num % 10;
		str = digit + str;
		num /= 10;
	}
	if (isNegative)
		str = "-" + str;
	return str;
}


int RPN::plus()
{
	int a;
	int b;
	_stack.pop();
	a = string_to_int(_stack.top());
	_stack.pop();
	b = string_to_int(_stack.top());
	if (a == -1 || b == -1)
		return (print_errmsg("wrong notation"));
	_stack.pop();
	_stack.push(int_to_string(b + a));
	return (0);
}

int RPN::minus()
{
	int a;
	int b;
	_stack.pop();
	a = string_to_int(_stack.top());
	_stack.pop();
	b = string_to_int(_stack.top());
	if (a == -1 || b == -1)
		return (print_errmsg("wrong notation"));
	_stack.pop();
	_stack.push(int_to_string(b - a));
	return (0);
}

int RPN::div()
{
	int a;
	int b;
	_stack.pop();
	a = string_to_int(_stack.top());
	_stack.pop();
	b = string_to_int(_stack.top());
	if (a == -1 || b == -1)
		return (print_errmsg("wrong notation"));
	_stack.pop();
	_stack.push(int_to_string(b / a));
	return (0);
}

int RPN::mult()
{
	int a;
	int b;
	_stack.pop();
	a = string_to_int(_stack.top());
	_stack.pop();
	b = string_to_int(_stack.top());
	if (a == -1 || b == -1)
		return (print_errmsg("wrong notation"));
	_stack.pop();
	_stack.push(int_to_string(b * a));
	return (0);
}

int RPN::calc(std::string str)
{
	std::string s;
	std::stringstream stream;
	int	num;

	stream.str(str);
	while (stream >> s)
	{
		num = string_to_int(s);
		if (num >= 0 && num <= 9 && s[0] != '-')
		{
			this->_stack.push(s);
		}
		else
		{
			if (s.size() == 1 && (s[0] == '*' || s[0] == '/' || s[0] == '+' || s[0] == '-'))
				this->_stack.push(s);
			else
				return(print_errmsg("invalid value inside."));
			if (_stack.size() >= 3)
			{
				if(_stack.top()[0] == '+')
				{
					if (plus())
						return (1);
				}
				else if(_stack.top()[0] == '-')
				{
					if (minus())
						return (1);
				}
				else if(_stack.top()[0] == '*')
				{
					if (mult())
						return (1);
				}
				else if(_stack.top()[0] == '/')
				{
					if (div())
						return (1);
				}
			}
		}
	}
	if (_stack.size() != 1)
	{
		while (_stack.size() != 0)
		{
			std::cout << _stack.top() << std::endl;
			_stack.pop();
		}
		return (print_errmsg("wrong notation"));
	}
	return (0);
}
