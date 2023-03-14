#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
			print_error_with_exit("could not open file.");
		else
			print_error_with_exit("too many arguments.");
	}
	BitcoinExchange be(argv[1]);
	return (0);
}
