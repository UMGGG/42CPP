#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
			std::string name;
			unsigned int Hit_points;
			unsigned int Energy_points;
			unsigned int Attack_damage;
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &claptrap);
			ClapTrap &operator=(const ClapTrap &claptrap);
			virtual void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			virtual ~ClapTrap();
};
#endif
