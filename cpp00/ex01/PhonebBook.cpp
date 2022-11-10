#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
	this->idx = 0;
}

void PhoneBook::add_contact()
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
	this->contacts[this->idx] = Contact(firstname, lastname, nickname, phonenum, secret);
	this->idx++;
	if (idx == 8)
		idx = 0;
	if (count != 8)
		this->count++;
}

std::string PhoneBook::get_short_string(std::string str)
{
	if ((int)(str.size()) > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	else
	{
		while ((int)(str.size()) != 10)
		{
			str = (" " + str);
		}
		return (str);
	}
}

void PhoneBook::show_contact(std::string idx)
{
	if (idx[0] >= '0' && idx[0] <= '7' && idx[1] == '\0' && (idx[0] - '0') < this->count)
	{
		this->contacts[(idx[0] - '0')].show_contact();
	}
	else
	{
		std::cout << "\"" << idx << "\" is not valid index" << std::endl;
	}
}

void PhoneBook::show_contact()
{
	int idx = 0;
	std::string idx2;

	if (this->count > 0)
	{
		while (idx < this->count)
		{
			std::cout << "         " << idx << "|";
			std::cout << get_short_string(this->contacts[idx].get_firstname()) << "|";
			std::cout << get_short_string(this->contacts[idx].get_lastname()) << "|";
			std::cout << get_short_string(this->contacts[idx].get_nickname()) << std::endl;
			idx++;
		}
		std::cout << "put index number for searching data"<< std::endl;
		std::cin >> idx2;
		this->show_contact(idx2);
	}
	else
	{
		std::cout << "Phonebook is empty" << std::endl;
	}
}

PhoneBook::~PhoneBook()
{
}
