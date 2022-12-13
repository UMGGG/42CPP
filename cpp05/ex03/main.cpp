#include "Intern.hpp"

int main()
{
	Intern *intern = new Intern();
	Bureaucrat *b = new Bureaucrat("jae", 1);
	AForm *a = intern->makeForm("shrubbery creation", "home");
	if (a == NULL)
	{
		delete b;
		delete intern;
	}
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
	delete intern;
	return (0);
}
