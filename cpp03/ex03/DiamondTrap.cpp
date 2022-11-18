#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): name(ClapTrap::name)
{
	ClapTrap::name = name + "_clap_name";
	std::cout << "DIA "<<this->name << "\'s Default constructor called" << std::endl;
	this->Attack_damage = FragTrap::Attack_damage;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
}

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap::name = name + "_clap_name";
	std::cout << "DIA "<<this->name << "\'s String constructor called" << std::endl;
	this->Attack_damage = FragTrap::Attack_damage;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diatrap)
{
	this->name = diatrap.name;
	std::cout << "DIA "<< this->name << "\'s String constructor called" << std::endl;
	this->Attack_damage = diatrap.Attack_damage;
	this->Hit_points = diatrap.Hit_points;
	this->Energy_points = diatrap.Energy_points;
}

void::DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void::DiamondTrap::whoAmI()
{
	std::cout << "DIA " << this->name << std::endl;
	std::cout << "CLAPTRAP " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DIA " << this->name << "\'s Default destructor called" << std::endl;
}
