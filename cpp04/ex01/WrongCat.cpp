#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat's Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongcat)
{
	std::cout << "WrongCat's Copy constructor called" << std::endl;
	*this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout << "WrongCat's Copy operator called" << std::endl;
	if (this != &wrongcat)
		this->type = wrongcat.type;
	return (*this);
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat say MMMMMMMMMMeow" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's Default destructor called" << std::endl;
}
