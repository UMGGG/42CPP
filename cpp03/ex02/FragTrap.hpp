#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
		public:
				FragTrap();
				FragTrap(std::string name);
				FragTrap(const FragTrap &fragtrap);
				FragTrap &operator=(const FragTrap &fragtrap);
				void attack(std::string const &target);
				void highFivesGuys(void);
				~FragTrap();
};

#endif
