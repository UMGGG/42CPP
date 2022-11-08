#include "phonebook.hpp"

int main(void)
{
	std::string	input;
	phonebook phonebooks;

	while (1)
	{
		std::cout << "input command (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			phonebooks.add_contact();
		}
		else if (input == "SEARCH")
		{
			phonebooks.show_contact();
		}
		else
			std::cout << "command not found \"" << input << "\" " << std::endl;
	}
	return (0);
}
