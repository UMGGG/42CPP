#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FRAG "<<this->name << "\'s Default constructor called" << std::endl;
	this->Attack_damage = 30;
	this->Energy_points = 100;
	this->Hit_points = 100;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	std::cout << "FRAG "<<this->name << "\'s String constructor called" << std::endl;
	this->Attack_damage = 30;
	this->Energy_points = 100;
	this->Hit_points = 100;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
	*this = fragtrap;
	std::cout <<"FRAG "<< this->name << "\'s Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	if (this != &fragtrap)
	{
		this->name = fragtrap.name;
		this->Attack_damage = fragtrap.Attack_damage;
		this->Energy_points = fragtrap.Energy_points;
		this->Hit_points = fragtrap.Hit_points;
	}
	std::cout << "FRAG " << this->name << "\'s Copy assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (this->Hit_points <= 0)
		std::cout << "FRAG " << this->name << " is already destroyed" << std::endl;
	else
		std::cout << "FRAG " << this->name << " request highfive someone!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FRAG " << this->name << "\'s Default destructor called" << std::endl;
}
