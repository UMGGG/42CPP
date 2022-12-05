#include "Form.hpp"

	void Form::checkSignGrade(int si_gr)
	{
		if (si_gr > 150)
			throw Form::GradeTooLowException();
		else if (si_gr < 1)
			throw Form::GradeTooHighException();
	}
	void Form::checkExecuteGrade(int ex_gr)
	{
		if (ex_gr > 150)
			throw Form::GradeTooLowException();
		else if (ex_gr < 1)
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
		try
		{
			checkSignGrade(si_gr);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(Form::GradeTooHighException &e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	Form::Form(std::string name_str, int si_gr, int ex_gr) : name(name_str), is_signed(false), sign_grade(si_gr), execute_grade(ex_gr)
	{
		std::cout << "Form's name, grade constructor called" << std::endl;
	}

	Form &Form::operator=(const Form &f)
	{
		std::cout << "Form's copy operator called" << std::endl;
		if (this == &f)
			return (*this);
		this->is_signed = f.getIsSigned();
		return (*this);
	}
	Form::~Form()
	{
		std::cout << "Form's default destructor called" << std::endl;
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
		out << "Name : " << a->getName() << "Signed : "<< a->getIsSigned() << "SignGrade : "<< a->getSignGrade() << "ExecuteGrade : "<< a->getExecuteGrade();
		return (out);
	}
