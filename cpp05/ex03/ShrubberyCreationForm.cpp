#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tar) : AForm("ShrubberyCreationForm", 145, 137), target(tar)
{
	std::cout << "ShrubberyCreationForm string constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f) : AForm("ShrubberyCreationForm", 145, 137), target(f.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = f;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	if(this->getIsSigned() == false)
	{
		std::cout << "Execute Form failed because Form isn't signed" << std::endl;
		throw AForm::FormNeedSignException();
	}
	else if(this->getExecuteGrade() < executor.getGrade())
	{
		std::cout << "Execute Form failed because Grade too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::string filename = this->getTarget();
		filename += "_shrubbery";
		std::ofstream writefile;
		std::string a = "       ###\n";
		a += "      #o###\n";
		a += "    #####o###\n";
		a += "   #o#\\#|#/###\n";
		a += "    ###\\|/#o#\n";
		a += "     # }|{  #\n";
		a += "       }|{\n";
		writefile.open(filename.c_str());
		if (writefile.fail())
		{
			std::cout << "can't make file \""<< this->getTarget() + "_shrubbery\"" << std::endl;
			return ;
		}
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		writefile.write(a.c_str(), a.length());
		writefile.close();
	}
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
	std::cout << "ShrubberyCreationForm's copy operator called" << std::endl;
	if (this == &f)
		return (*this);
	AForm::operator=(f);
	const_cast<std::string&>(this->target) = f.getTarget();
	return (*this);
}
