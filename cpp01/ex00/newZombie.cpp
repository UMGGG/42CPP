#include "Zombie.hpp"

	Zombie *Zombie::newZombie(std::string sname)
	{
		Zombie *newzom = new Zombie(sname);
		return (newzom);
	}
