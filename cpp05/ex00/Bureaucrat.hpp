#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
			const std::string name;
			int grade;
	public:
			Bureaucrat();
			Bureaucrat(const Bureaucrat &bur);
			Bureaucrat &operator=(const Bureaucrat &bur);
			~Bureaucrat();
			std::string getName() const;
			int getGrade() const;
			void incGrade();
			void decGrade();
};

#endif
