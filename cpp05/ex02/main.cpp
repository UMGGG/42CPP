#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	ShrubberyCreationForm *a = new ShrubberyCreationForm("default");
	std::cout << a->getTarget() << std::endl;
	delete a;
	return (0);
}
