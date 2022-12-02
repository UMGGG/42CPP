#include "Zombie.hpp"

	Zombie::Zombie()
	{
	}

	Zombie::Zombie(std::string sname)
	{
		name = sname;
	}

	void Zombie::announce(void)
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}

	Zombie::~Zombie()
	{
		std::cout << name << " is dead..." << std::endl;
	}
