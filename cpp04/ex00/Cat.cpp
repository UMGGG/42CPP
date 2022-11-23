#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat's Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal()
{
	this->type = cat.type;
	std::cout << "Cat's Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
		this->type = cat.type;
	std::cout << "Cat's Copy operator called" << std::endl;
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
}
