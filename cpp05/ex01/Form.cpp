#include "Form.hpp"

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
		// 처리하기
	}

	Form::Form(std::string name_str, int si_gr, int ex_gr) : name(name_str), is_signed(false), sign_grade(si_gr), execute_grade(ex_gr)
	{
		std::cout << "Form's name, grade constructor called" << std::endl;
		// 처리하기
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

	void Form::besigned(Bureaucrat &b)
	{
		if (b.getGrade() <= this->getSignGrade())
		{
			std::cout << b.getName() << "signed" << this->getName() << std:: endl;
			this->is_signed = true;
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
		out << "Name : " << a->getName() << "Signed : "<< a->getIsSigned() << "SignGrade : "<< a->getSignGrade() << "ExecuteGrade : "<< a->getExecuteGrade();
		return (out);
	}
