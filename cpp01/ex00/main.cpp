#include "Zombie.hpp"

int main(void)
{
	Zombie zom("Foo");

	zom.announce();
	Zombie *newzom = newZombie("Foo2");
	newzom->announce();
	randomChump("Foo3");
	Zombie zom2("Foo4");
	delete(newzom);
	return (0);
}
