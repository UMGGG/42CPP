#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal's Default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	this->type = animal.type;
	std::cout << "Animal's Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this != &animal)
		this->type = animal.type;
	std::cout << "Animal's Copy operator called" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal say nothing.." << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << "Animal's Default destructor called" << std::endl;
}
