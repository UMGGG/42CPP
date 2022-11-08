#ifndef CONTACT_HPP
# define CONTACT_HPP

#	include <iostream>

class contact
{
	private:
			std::string firstname;
			std::string lastname;
			std::string nickname;
			std::string phonenum;
			std::string secret;
	public:
	contact();
	contact(std::string firstname, std::string lastname, \
	std::string nickname, std::string phonenum, std::string secret);
	std::string get_firstname();
	std::string get_lastname();
	std::string get_nickname();
	~contact();
};

#endif
