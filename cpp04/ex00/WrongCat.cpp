#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat's Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat) : WrongAnimal()
{
	this->type = wrongcat.type;
	std::cout << "WrongCat's Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	if (this != &wrongcat)
		this->type = wrongcat.type;
	std::cout << "WrongCat's Copy operator called" << std::endl;
	return (*this);
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat say Meow" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's Default destructor called" << std::endl;
}
