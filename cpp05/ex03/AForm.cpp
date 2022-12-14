#include "AForm.hpp"

void checkGrade(int gr, int gr2)
{
	if (gr > 150 || gr2 > 150)
		throw AForm::GradeTooLowException();
	else if (gr < 1 || gr2 < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm() : name("default"), is_signed(false), sign_grade(150), execute_grade(150)
{
	std::cout << "AForm's default constructor called" << std::endl;
}

AForm::AForm(const AForm &f) : name(f.getName() + "_copy"), is_signed(false), sign_grade(f.getSignGrade()), execute_grade(f.getExecuteGrade())
{
	std::cout << "AForm's copy constructor called" << std::endl;
}

AForm::AForm(std::string name_str) : name(name_str), is_signed(false), sign_grade(150), execute_grade(150)
{
	std::cout << "AForm's name constructor called" << std::endl;
}

AForm::AForm(int si_gr, int ex_gr) : name("default"), is_signed(false), sign_grade(si_gr), execute_grade(ex_gr)
{
	std::cout << "AForm's grade constructor called" << std::endl;
	// try
	// {
		checkGrade(si_gr, ex_gr);
	// }
	// catch(AForm::GradeTooLowException &e)
	// {
	// 	std::cerr << "AForm's grade set wrong " << e.what() << '\n';
	// }
	// catch(AForm::GradeTooHighException &e)
	// {
	// 	std::cerr << "AForm's grade set wrong " << e.what() << '\n';
	// }
}

AForm::AForm(std::string name_str, int si_gr, int ex_gr) : name(name_str), is_signed(false), sign_grade(si_gr), execute_grade(ex_gr)
{
	std::cout << "AForm's name, grade constructor called" << std::endl;
	// try
	// {
		checkGrade(si_gr, ex_gr);
	// }
	// catch(AForm::GradeTooLowException &e)
	// {
	// 	std::cerr << "AForm's grade set wrong " << e.what() << '\n';
	// }
	// catch(AForm::GradeTooHighException &e)
	// {
	// 	std::cerr << "AForm's grade set wrong " << e.what() << '\n';
	// }
}

AForm &AForm::operator=(const AForm &f)
{
	std::cout << "AForm's copy operator called" << std::endl;
	if (this == &f)
		return (*this);
	this->is_signed = f.getIsSigned();
	const_cast<std::string &>(this->name) = f.getName();
	const_cast<int &>(this->sign_grade) = f.getSignGrade();
	const_cast<int &>(this->execute_grade) = f.getExecuteGrade();
	return (*this);
}
AForm::~AForm()
{
	std::cout << "AForm's default destructor called" << std::endl;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getSignGrade() && this->getIsSigned() == false)
	{
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
		this->is_signed = true;
	}
	else if (this->getIsSigned() == true)
	{
		std::cout << b.getName() << " couldn’t sign " << this->getName() << " because form already signed"<<std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn’t sign " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
}

int AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int AForm::getExecuteGrade() const
{
	return (this->execute_grade);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

const std::string AForm::getName() const
{
	return (this->name);
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char* AForm::FormNeedSignException::what(void) const throw()
{
	return ("Form isn't signed");
}

std::ostream &operator<<(std::ostream &out, AForm *a)
{
	out << "Name: " << a->getName() << std::boolalpha << ", Signed: "<< a->getIsSigned() << ", SignGrade: "<< a->getSignGrade() << ", ExecuteGrade: "<< a->getExecuteGrade();
	return (out);
}
