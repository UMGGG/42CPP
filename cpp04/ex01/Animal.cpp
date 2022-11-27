#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal's Default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal's Copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal's Copy operator called" << std::endl;
	if (this != &animal)
		this->type = animal.type;
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
