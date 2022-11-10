#include "Zombie.hpp"

void Zombie::randomChump(std::string sname)
{
	Zombie zom(sname);
	zom.announce();
}
