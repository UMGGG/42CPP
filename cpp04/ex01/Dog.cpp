#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog's Default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog's Copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog's Copy operator called" << std::endl;
	this->type = dog.type;
	*(this->brain) = *(dog.brain);
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
	delete this->brain;
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}
