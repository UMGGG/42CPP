#include "Form.hpp"

int main()
{
	{
		Bureaucrat *c = new Bureaucrat("Jae", 1);
		Form *e = NULL;
		try
		{
			e = new Form("zxc", 120, 110);
		}
		catch(Form::GradeTooHighException &e)
		{
			std::cerr << "new Form's " << e.what() << '\n';
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << "new Form's " << e.what() << '\n';
		}
		try
		{
			e->besigned(*c);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		e->besigned(*c);
		std::cout << e << std::endl;
		delete c;
		delete e;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat *c = new Bureaucrat();
		Form *e = new Form("dkdk", 110, 100);
		try
		{
			e->besigned(*c);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		delete c;
		delete e;
	}
	return (0);
}
