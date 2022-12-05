#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Form
{
	private:
			const std::string name;
			bool is_signed;
			const int sign_grade;
			const int execute_grade;
			void checkSignGrade(int si_gr);
			void checkExecuteGrade(int ex_gr);
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
			const int getSignGrade() const;
			const int getExecuteGrade() const;

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
