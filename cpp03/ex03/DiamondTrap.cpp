#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(), name(ClapTrap::name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = "defaultDIA";
	this->Attack_damage = FragTrap::Attack_damage;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	std::cout << "DIA "<<this->name << "\'s Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	this->Attack_damage = FragTrap::Attack_damage;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	std::cout << "DIA "<<this->name << "\'s String constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diatrap)
{
	if (this != &diatrap)
	{
		this->name = diatrap.name;
		this->Attack_damage = diatrap.Attack_damage;
		this->Energy_points = diatrap.Energy_points;
		this->Hit_points = diatrap.Hit_points;
	}
	std::cout << "DIA " << this->name << "\'s Copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &diatrap): ClapTrap(diatrap), FragTrap(diatrap), ScavTrap(diatrap)
{
	*this = diatrap;
	std::cout << "DIA "<< this->name << "\'s Copy constructor called" << std::endl;
}

void::DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void::DiamondTrap::whoAmI()
{
	std::cout << "DIA name is " << this->name << std::endl;
	std::cout << "CLAPTRAP name is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DIA " << this->name << "\'s Default destructor called" << std::endl;
}
