#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
			const std::string name;
			bool is_signed;
			const int sign_grade;
			const int execute_grade;
	public:
			AForm();
			AForm(const AForm &f);
			AForm(std::string name_str);
			AForm(int si_gr, int ex_gr);
			AForm(std::string name_str, int si_gr, int ex_gr);
			AForm &operator=(const AForm &f);
			virtual ~AForm();
			const std::string getName() const;
			bool getIsSigned() const;
			int getSignGrade() const;
			int getExecuteGrade() const;
			void beSigned(Bureaucrat &b);
			virtual void execute(Bureaucrat const & executor)const = 0;

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

	class FormNeedSignException : public std::exception
	{
		public:
				const char* what( void ) const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm *a);

#endif
