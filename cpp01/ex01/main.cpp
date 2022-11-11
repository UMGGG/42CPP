#include "Zombie.hpp"

int main(void)
{
	Zombie *zom_horde = zombieHorde(5, "zom");
	for (int i = 0 ; i < 5 ; i++)
	{
		zom_horde[i].announce();
	}
	delete[] (zom_horde);
}
