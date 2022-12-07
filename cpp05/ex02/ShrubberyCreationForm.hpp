#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
			const std::string target;
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string tar);
			ShrubberyCreationForm(const ShrubberyCreationForm &f);
			~ShrubberyCreationForm();
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
			std::string getTarget() const;
			void execute(Bureaucrat const & executor)const;
};
