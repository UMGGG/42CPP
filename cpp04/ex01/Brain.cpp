#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain's Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain's Copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain's Copy operator called" << std::endl;
	Brain *a = new Brain();
	for (int i = 0; i < 100 ; i++)
		a->ideas[i] = brain.ideas[i];
	return (*a);
}

Brain::~Brain()
{
	std::cout << "Brain's Default destructor called" << std::endl;
}
