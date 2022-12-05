#include "Form.hpp"

int main()
{
	Bureaucrat *a = new Bureaucrat();
	Bureaucrat *b = new Bureaucrat("asdd");
	Bureaucrat *c = new Bureaucrat(1);
	Bureaucrat *d = new Bureaucrat("newB", 160);
	Form *e = new Form("zxc", 160, 120);
	b->decGrade();
	c->incGrade();
	c->decGrade();
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	return (0);
}
