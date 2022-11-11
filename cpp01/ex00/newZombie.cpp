#include "Zombie.hpp"

	Zombie *newZombie(std::string sname)
	{
		Zombie *newzom = new Zombie(sname);
		return (newzom);
	}
