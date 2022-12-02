#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat's Default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat's Copy constructor called" << std::endl;
	*this = cat;
}

Cat::Cat(const Brain &brain)
{
	std::cout << "Cat's Brain Copy constructor called" << std::endl;
	this->type = "Cat";
	*this->brain = brain;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat's Copy operator called" << std::endl;
	if (this != &cat)
	{
		this->type = cat.type;
		this->brain = cat.brain;
	}
	return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "Cat say Meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's Default destructor called" << std::endl;
	delete this->brain;
}
