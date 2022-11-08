#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

# include "contact.hpp"

class phonebook
{
	private:
			contact	contacts[8];
			int		idx;
			int		count;
	public:
			phonebook();
			void add_contact();
			void show_contact();
			~phonebook();
};

#endif
