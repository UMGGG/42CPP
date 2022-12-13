#pragma once

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
	public:
			Intern();
			Intern(const Intern &intern);
			Intern &operator=(const Intern &intern);
			AForm *makeForm(std::string name, std::string target);
			~Intern();
};
