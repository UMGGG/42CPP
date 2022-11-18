#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "default scavtrap";
	std::cout << "SCAV "<<this->name << "\'s Default constructor called" << std::endl;
	this->Attack_damage = 20;
	this->Energy_points = 50;
	this->Hit_points = 100;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	std::cout << "SCAV "<<this->name << "\'s String constructor called" << std::endl;
	this->Attack_damage = 20;
	this->Energy_points = 50;
	this->Hit_points = 100;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)
{
	*this = scavtrap;
	std::cout <<"SCAV "<< this->name << "\'s Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	if (this != &scavtrap)
	{
		this->name = scavtrap.name;
		this->Attack_damage = scavtrap.Attack_damage;
		this->Energy_points = scavtrap.Energy_points;
		this->Hit_points = scavtrap.Hit_points;
	}
	std::cout << "SCAV " << this->name << "\'s Copy assignment operator called" << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	if (this->Hit_points <= 0)
		std::cout << "SCAV " << this->name << " is already destroyed" << std::endl;
	else
		std::cout << "SCAV " << this->name << " is now on guardGate mode" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->Hit_points <= 0)
		std::cout << "SCAV " << this->name << " is already destroyed" << std::endl;
	else if (this->Energy_points <= 0)
		std::cout << "SCAV "  << this->name << " Not enough Energy_points" << std::endl;
	else
	{
		std::cout << "SCAV "  << "\"" << this->name << "\" attacks \"" << target << "\", causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points--;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAV " << this->name << "\'s Default destructor called" << std::endl;
}
