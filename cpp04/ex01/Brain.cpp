#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain's Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain's copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain's copy operator called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain's Default destructor called" << std::endl;
}
