#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), Hit_points(10),Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap's Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string clap_name): name(clap_name), Hit_points(10),Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap's String constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << this->name << "'s Copy assignment operator called" << std::endl;
	if (this != &claptrap)
	{
		this->name = claptrap.name;
		this->Attack_damage = claptrap.Attack_damage;
		this->Energy_points = claptrap.Energy_points;
		this->Hit_points = claptrap.Hit_points;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap's Copy constructor called" << std::endl;
	*this = claptrap;
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
	if (this->Hit_points != 0)
	{
		std::cout << "ClapTrap \"" << this->name << "\" get \"" << amount << "\" points of damage" << std::endl;
		if (this->Hit_points >= amount)
			this->Hit_points -= amount;
		else
			this->Hit_points = 0;
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
	std::cout << "ClapTrap's Default destructor called" << std::endl;
}
