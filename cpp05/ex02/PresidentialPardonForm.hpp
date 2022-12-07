#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
			const std::string target;
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(std::string tar);
			PresidentialPardonForm(const PresidentialPardonForm &r);
			~PresidentialPardonForm();
			PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
			std::string getTarget() const;
			void execute(Bureaucrat const & executor)const;
};
