#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
			std::string firstname;
			std::string lastname;
			std::string nickname;
			std::string phonenum;
			std::string secret;
	public:
	Contact();
	Contact(std::string firstname, std::string lastname, \
	std::string nickname, std::string phonenum, std::string secret);
	std::string get_firstname();
	std::string get_lastname();
	std::string get_nickname();
	void		show_contact();
	~Contact();
};

#endif
