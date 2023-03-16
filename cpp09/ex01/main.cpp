#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc == 1)
			return (print_errmsg ("no arguments"));
		else
			return (print_errmsg ("too many arguments"));
	}
	else
	{
		RPN first_rpn(argv[1]);
	}
	return (0);
}
