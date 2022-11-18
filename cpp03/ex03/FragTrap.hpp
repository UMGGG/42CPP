#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
		public:
				FragTrap();
				FragTrap(std::string name);
				FragTrap(const FragTrap &fragtrap);
				FragTrap &operator=(const FragTrap &fragtrap);
				void highFivesGuys(void);
				~FragTrap();
};

#endif
