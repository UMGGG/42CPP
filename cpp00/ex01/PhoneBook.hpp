#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

# include "Contact.hpp"

class PhoneBook
{
	private:
			Contact	contacts[8];
			int		idx;
			int		count;
			std::string get_short_string(std::string str);
			void show_contact(std::string idx);
	public:
			PhoneBook();
			void add_contact();
			void show_contact();
			~PhoneBook();
};

#endif
