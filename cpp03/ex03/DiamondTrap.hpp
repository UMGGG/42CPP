#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
			std::string name;
	public:
			DiamondTrap();
			DiamondTrap(std::string name);
			DiamondTrap(const DiamondTrap &diatrap);
			DiamondTrap &operator=(const DiamondTrap &diatrap);
			void whoAmI();
			void attack(const std::string &target);
			~DiamondTrap();
};

#endif
