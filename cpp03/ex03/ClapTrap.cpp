#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->Attack_damage = 0;
	this->Energy_points = 10;
	this->Hit_points = 10;
	std::cout << this->name << "\'s Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->Attack_damage = 0;
	this->Energy_points = 10;
	this->Hit_points = 10;
	std::cout << this->name << "\'s String constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	if (this != &claptrap)
	{
		this->name = claptrap.name;
		this->Attack_damage = claptrap.Attack_damage;
		this->Energy_points = claptrap.Energy_points;
		this->Hit_points = claptrap.Hit_points;
	}
	std::cout << this->name << "\'s Copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	std::cout << this->name << "\'s Copy constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->Hit_points <= 0)
		std::cout << this->name << "can't attack. " << this->name << "is already destroyed" << std::endl;
	else if (this->Energy_points <= 0)
		std::cout << this->name << " Not enough Energy_points" << std::endl;
	else
	{
		std::cout << "ClapTrap \"" << this->name << "\" attacks \"" << target << "\", causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hit_points != 0 && this->Hit_points >= amount)
	{
		std::cout << "ClapTrap \"" << this->name << "\" get \"" << amount << "\" points of damage" << std::endl;
		this->Hit_points -= amount;
	}
	else
	{
		std::cout << "ClapTrap \"" << this->name << "\" is already destroyed" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit_points <= 0)
		std::cout << this->name << " is already destroyed" << std::endl;
	else if (this->Energy_points >= 1)
	{
		std::cout << "ClapTrap \"" << this->name << "\" repaired " << amount << " point" << std::endl;
		this->Energy_points--;
		this->Hit_points += amount;
	}
	else
		std::cout << this->name << " Not enough Energy_points" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << "\'s Default destructor called" << std::endl;
}
