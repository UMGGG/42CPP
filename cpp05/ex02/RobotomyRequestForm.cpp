#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string tar) : AForm("RobotomyRequestForm", 72, 45), target(tar)
{
	std::cout << "RobotomyRequestForm string constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f) : AForm("RobotomyRequestForm", 72, 45), target(f.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = f;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
	if(this->getIsSigned() == false)
	{
		std::cout << "Execute Form failed because ";
		throw AForm::FormNeedSignException();
	}
	else if(this->getExecuteGrade() < executor.getGrade())
	{
		std::cout << "Execute Form failed because ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		srand(time(NULL));
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		if (rand() % 2 == 0)
			std::cout << "drrrrrrrrrrrrrrrrrrrrrrrrrr " << this->getTarget() << " has been robotomized" << std::endl;
		else
			std::cout << this->getTarget() << " failed to robotomized" << std::endl;
	}
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
	std::cout << "RobotomyRequestForm's copy operator called" << std::endl;
	if (this == &f)
		return (*this);
	return (*this);
}
