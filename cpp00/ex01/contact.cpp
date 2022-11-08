#include "contact.hpp"

contact::contact(std::string firstname, std::string lastname, \
	std::string nickname, std::string phonenum, std::string secret)
	{
		this->firstname = firstname;
		this->lastname = lastname;
		this->nickname = nickname;
		this->phonenum = phonenum;
		this->secret = secret;
	}

contact::contact()
{
	contact("", "", "", "", "");
}

contact::~contact()
{
}

std::string contact::get_firstname()
{
	return (this->firstname);
}

std::string contact::get_lastname()
{
	return (this->lastname);
}

std::string contact::get_nickname()
{
	return (this->nickname);
}
