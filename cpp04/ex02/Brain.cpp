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
	for (int i = 0; i < 100 ; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain's Default destructor called" << std::endl;
}

void Brain::setIdeas(std::string str, int i)
{
	if (i < 100 && i >= 0)
	{
		this->ideas[i] = str;
	}
}
void Brain::setAllIdeas(std::string str)
{
	for(int i = 0 ; i < 100 ; i++)
	{
		this->ideas[i] = str;
	}
}
std::string Brain::getIdeas(int i) const
{
	if (i < 100 && i >= 0)
	{
		return (this->ideas[i]);
	}
	return (NULL);
}
