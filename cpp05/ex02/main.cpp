#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		Bureaucrat *b = new Bureaucrat("jae", 140);
		ShrubberyCreationForm *a = new ShrubberyCreationForm("home");
		b->signForm(*a);
		try
		{
			b->executeForm(*a);
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(AForm::FormNeedSignException& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete a;
		delete b;
	}
	std::cout << "-------------------------------------------------" << std::endl;
	{
		Bureaucrat *b = new Bureaucrat("jae", 1);
		PresidentialPardonForm *a = new PresidentialPardonForm("home");
		b->signForm(*a);
		try
		{
			b->executeForm(*a);
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(AForm::FormNeedSignException& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete a;
		delete b;
	}
	std::cout << "-------------------------------------------------" << std::endl;
	{
		Bureaucrat *b = new Bureaucrat("jae", 1);
		RobotomyRequestForm *a = new RobotomyRequestForm("home");
		RobotomyRequestForm *c = new RobotomyRequestForm(*a);
		b->signForm(*a);
		b->signForm(*c);
		try
		{
			b->executeForm(*a);
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(AForm::FormNeedSignException& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete a;
		delete b;
		delete c;
	}
	return (0);
}
