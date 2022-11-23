#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap E("E");
	DiamondTrap K("T");

	E.attack("A");
	E.whoAmI();
	E.highFivesGuys();
	E.attack("D");
	K.attack("C");
}
