#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *a = new Bureaucrat();
	Bureaucrat *b = new Bureaucrat("asdd");
	Bureaucrat *c = new Bureaucrat(1);
	Bureaucrat *d = new Bureaucrat("newB", 160);
	b->decGrade();
	c->incGrade();
	c->decGrade();
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;
	delete a;
	delete b;
	delete c;
	delete d;
	return (0);
}
