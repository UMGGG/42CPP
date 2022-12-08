#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string tar) : AForm("PresidentialPardonForm", 25, 5), target(tar)
{
	std::cout << "PresidentialPardonForm string constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f) : AForm("PresidentialPardonForm", 25, 5), target(f.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = f;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
	std::cout << executor.getName() << "execute" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &f)
{
	std::cout << "PresidentialPardonForm's copy operator called" << std::endl;
	if (this == &f)
		return (*this);
	return (*this);
}
