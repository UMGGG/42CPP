#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal's Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	std::cout << "WrongAnimal's Copy constructor called" << std::endl;
	*this = wronganimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	std::cout << "WrongAnimal's Copy operator called" << std::endl;
	if (this != &wronganimal)
		this->type = wronganimal.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal say nothing.." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's Default destructor called" << std::endl;
}
