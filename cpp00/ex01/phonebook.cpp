#include "phonebook.hpp"

phonebook::phonebook()
{
	this->count = 0;
	this->idx = 0;
}

void phonebook::add_contact()
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenum;
	std::string secret;

	std::cout << "firstname : ";
	std::cin >> firstname;
	std::cout << "lastname : ";
	std::cin >> lastname;
	std::cout << "nickname : ";
	std::cin >> nickname;
	std::cout << "phonenum : ";
	std::cin >> phonenum;
	std::cout << "secret : ";
	std::cin >> secret;
	this->contacts[this->idx] = contact(firstname, lastname, nickname, phonenum, secret);
	this->idx++;
	if (idx == 8)
		idx = 0;
	if (count != 8)
		this->count++;
}

void phonebook::show_contact()
{
	int idx = 0;

	if (this->count > 0)
	{
		while (idx < this->count)
		{
			std::cout << "index : "<<idx << std::endl;
			std::cout << this->contacts[idx].get_firstname() << std::endl;
			std::cout << this->contacts[idx].get_lastname() << std::endl;
			std::cout << this->contacts[idx].get_nickname() << std::endl;
			idx++;
		}
	}
	else
	{
		std::cout << "Phonebook is empty" << std::endl;
	}
}

phonebook::~phonebook()
{
}
