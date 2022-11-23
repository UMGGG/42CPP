#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog's Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal()
{
	this->type = dog.type;
	std::cout << "Dog's Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
		this->type = dog.type;
	std::cout << "Dog's Copy operator called" << std::endl;
	return (*this);
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
	std::cout << "Dog say Bark" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's Default destructor called" << std::endl;
}
