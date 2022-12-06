#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
			const std::string name;
			bool is_signed;
			const int sign_grade;
			const int execute_grade;
	public:
			Form();
			Form(const Form &f);
			Form(std::string name_str);
			Form(int si_gr, int ex_gr);
			Form(std::string name_str, int si_gr, int ex_gr);
			Form &operator=(const Form &f);
			~Form();
			const std::string getName() const;
			bool getIsSigned() const;
			int getSignGrade() const;
			int getExecuteGrade() const;
			void besigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
				const char* what( void ) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
				const char* what( void ) const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form *a);

#endif
