#include "Contact.hpp"

Contact::Contact(std::string firstname, std::string lastname, \
	std::string nickname, std::string phonenum, std::string secret)
	{
		this->firstname = firstname;
		this->lastname = lastname;
		this->nickname = nickname;
		this->phonenum = phonenum;
		this->secret = secret;
	}

Contact::Contact()
{
	Contact("", "", "", "", "");
}

Contact::~Contact()
{
}

std::string Contact::get_firstname()
{
	return (this->firstname);
}

std::string Contact::get_lastname()
{
	return (this->lastname);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

void	Contact::show_contact()
{
	std::cout << "firstname : " << this->firstname << std::endl;
	std::cout << "lastname : " << this->lastname << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phonenumber : " << this->phonenum << std::endl;
	std::cout << "secret : " << this->secret << std::endl;
}
