#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Bureaucrat's default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.getName() + "_copy"), grade(bur.getGrade())
{
	std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string namestr) : name(namestr), grade(150)
{
	std::cout << "Bureaucrat's name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int gr) : name("Default")
{
	try
	{
		std::cout << "Bureaucrat's grade constructor called" << std::endl;
		this->setGrade(gr);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << this->getName() << " Set grade fail " << e.what() << " so grade set to 150" <<std::endl;
		this->setGrade(150);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << this->getName()  << " Set grade fail "  << e.what() << " so grade set to 150"  << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(std::string namestr, int gr) : name(namestr)
{
	try
	{
		std::cout << "Bureaucrat's name,grade constructor called" << std::endl;
		this->setGrade(gr);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << this->getName()  << " Set grade fail " << e.what() << " so grade set to 150" <<std::endl;
		this->setGrade(150);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << this->getName()  << " Set grade fail "  << e.what() << " so grade set to 150"  << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur)
{
	std::cout << "Bureaucrat's copy operator called" << std::endl;
	if (this == &bur)
		return (*this);
	this->grade = bur.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " Bureaucrat default destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int gr)
{
	if (gr > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (gr < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = gr;
}

void Bureaucrat::incGrade()
{
	try
	{
		this->setGrade(this->grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << this->getName()  << " incGrade fail " << e.what() << '\n';
	}
}

void Bureaucrat::decGrade()
{
	try
	{
		this->setGrade(this->grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << this->getName()  << " decGrade fail "  << e.what() << '\n';
	}
}

void Bureaucrat::signForm(std::string form_name, int i)
{
	if (i == 1)
		std::cout << this->getName() << " signed " << form_name << std::endl;
	else if (i == 2)
		std::cout << this->getName() << " couldn’t sign " << form_name << " because form already signed"<<std::endl;
	else if (i == 3)
		std::cout << this->getName() << " couldn’t sign " << form_name << " because ";

}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat *a)
{
	out << a->getName() << ", bureaucrat grade "<< a->getGrade() << ".";
	return (out);
}
