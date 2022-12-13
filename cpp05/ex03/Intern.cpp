#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	std::cout << "Intern copy operator called" << std::endl;
	if (this == &intern)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string a[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i = 0;
	for (i = 0 ; i < 3 ; i++)
		if (a[i] == name)
			break;
	switch (i)
	{
	case 0:
		{
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));
		}
	case 1:
		{
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));
		}
	case 2:
		{
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		}
	default:
		std::cout << "Intern can't create form " << name << std::endl;
	}
	return NULL;
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called" << std::endl;
}
