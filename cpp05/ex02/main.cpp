#include "AForm.hpp"

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
		std::cout << e << std::endl;
		e->besigned(*c);
		e->besigned(*c);
		std::cout << e << std::endl;
		delete c;
		delete e;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat *c = new Bureaucrat("Jae2", 149);
		Form *e = new Form(110, 100);
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
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	{
		Form *e = NULL;
		try
		{
			e = new Form(190, 100);
		}
		catch(Form::GradeTooLowException &e) // 스택을 자동으로 회수해줌
		{
			std::cerr << "Form created fail "<< e.what() << '\n';
		}
		if (e != NULL)
			delete e;
	}
	system("leaks ex01");
	return (0);
}
