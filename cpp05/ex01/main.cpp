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
		std::cout << e << std::endl;
		c->signForm(*e);
		c->signForm(*e);
		std::cout << c << std::endl;
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
			c->signForm(*e);
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
			e = new Form(190, 122); // throw가 생기기때문에 저장공간이 할당되지않고 catch로 빠져나옴
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << "Form created fail "<< e.what() << '\n';
		}
		catch(Form::GradeTooHighException &e)
		{
			std::cerr << "Form created fail "<< e.what() << '\n';
		}
		if (e != NULL)
			delete e;
	}
	return (0);
}
