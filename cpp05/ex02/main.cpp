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
	return (0);
}
