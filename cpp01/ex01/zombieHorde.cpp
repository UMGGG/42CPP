#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	std::string name_num = "0";
	Zombie *zombie_horde = new Zombie[N];
	for (int i = 0; i < N ; i++)
	{
		zombie_horde[i].set_name(name + name_num);
		name_num[0]++;
		std::cout << zombie_horde[i].get_name() << " is wakeup" << std::endl;
	}
	return (zombie_horde);
}
