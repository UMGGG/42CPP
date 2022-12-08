#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <AForm.hpp>

class Bureaucrat
{
	private:
			const std::string name;
			int grade;
			void setGrade(int grade);
	public:
			Bureaucrat();
			Bureaucrat(const Bureaucrat &bur);
			Bureaucrat(std::string namestr);
			Bureaucrat(int gr);
			Bureaucrat(std::string namestr, int gr);
			Bureaucrat &operator=(const Bureaucrat &bur);
			~Bureaucrat();
			const std::string getName() const;
			int getGrade() const;
			void incGrade();
			void decGrade();
			void signForm(std::string form_name, int i);
			void executeForm(AForm const &form);

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

std::ostream &operator<<(std::ostream &out, Bureaucrat *a);

#endif
