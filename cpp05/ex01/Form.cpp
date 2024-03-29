#include "Form.hpp"

	void checkGrade(int gr, int gr2)
	{
		if (gr > 150 || gr2 > 150)
			throw Form::GradeTooLowException();
		else if (gr < 1 || gr2 < 1)
			throw Form::GradeTooHighException();
	}

	Form::Form() : name("default"), is_signed(false), sign_grade(150), execute_grade(150)
	{
		std::cout << "Form's default constructor called" << std::endl;
	}

	Form::Form(const Form &f) : name(f.getName() + "_copy"), is_signed(false), sign_grade(f.getSignGrade()), execute_grade(f.getExecuteGrade())
	{
		std::cout << "Form's copy constructor called" << std::endl;
	}

	Form::Form(std::string name_str) : name(name_str), is_signed(false), sign_grade(150), execute_grade(150)
	{
		std::cout << "Form's name constructor called" << std::endl;
	}

	Form::Form(int si_gr, int ex_gr) : name("default"), is_signed(false), sign_grade(si_gr), execute_grade(ex_gr)
	{
		std::cout << "Form's grade constructor called" << std::endl;
		// try
		// {
			checkGrade(si_gr, ex_gr);
		// }
		// catch(Form::GradeTooLowException &e)
		// {
		// 	std::cerr << "Form's grade set wrong " << e.what() << '\n';
		// }
		// catch(std::execption &e)
		// {
		// 	std::cerr << "Form's grade set wrong " << e.what() << '\n';
		// }
	}

	Form::Form(std::string name_str, int si_gr, int ex_gr) : name(name_str), is_signed(false), sign_grade(si_gr), execute_grade(ex_gr)
	{
		std::cout << "Form's name, grade constructor called" << std::endl;
		// try
		// {
			checkGrade(si_gr, ex_gr);
		// }
		// catch(Form::GradeTooLowException &e)
		// {
		// 	std::cerr << "Form's grade set wrong " << e.what() << '\n';
		// }
		// catch(Form::GradeTooHighException &e)
		// {
		// 	std::cerr << "Form's grade set wrong " << e.what() << '\n';
		// }
	}

	Form &Form::operator=(const Form &f)
	{
		std::cout << "Form's copy operator called" << std::endl;
		if (this == &f)
			return (*this);
		this->is_signed = f.getIsSigned();
		const_cast<std::string &>(this->name) = f.getName();
		const_cast<int &>(this->sign_grade) = f.getSignGrade();
		const_cast<int &>(this->execute_grade) = f.getExecuteGrade();
		return (*this);
	}
	Form::~Form()
	{
		std::cout << "Form's default destructor called" << std::endl;
	}

	void Form::beSigned(Bureaucrat &b)
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
			std::cout << b.getName() << " couldn’t sign " << this->getName() << " because Grade too low" << std::endl;
			throw Form::GradeTooLowException();
		}
	}

	int Form::getSignGrade() const
	{
		return (this->sign_grade);
	}

	int Form::getExecuteGrade() const
	{
		return (this->execute_grade);
	}

	bool Form::getIsSigned() const
	{
		return (this->is_signed);
	}

	const std::string Form::getName() const
	{
		return (this->name);
	}

	const char* Form::GradeTooLowException::what(void) const throw()
	{
		return ("Grade too low");
	}

	const char* Form::GradeTooHighException::what(void) const throw()
	{
		return ("Grade too high");
	}

	std::ostream &operator<<(std::ostream &out, Form *a)
	{
		out << "Name: " << a->getName() << std::boolalpha << ", Signed: "<< a->getIsSigned() << ", SignGrade: "<< a->getSignGrade() << ", ExecuteGrade: "<< a->getExecuteGrade();
		return (out);
	}
