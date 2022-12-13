#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat's Default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat's Copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat's Copy operator called" << std::endl;
	if (this != &cat)
		this->type = cat.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat say Meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's Default destructor called" << std::endl;
}
