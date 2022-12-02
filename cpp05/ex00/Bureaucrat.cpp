#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Bureaucrat's default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.getName() + "_copy"), grade(bur.getGrade())
{
	std::cout << "Bureaucrat's default constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur)
{
	std::cout << "Bureaucrat's copy operator called" << std::endl;
	this->name = bur.getName();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat's default destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->getName());
}

int Bureaucrat::getGrade() const
{
	return (this->getGrade());
}

void Bureaucrat::incGrade()
{

}

void Bureaucrat::decGrade()
{

}
