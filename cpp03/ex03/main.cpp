#include "DiamondTrap.hpp"

int main()
{
	ClapTrap A("A");
	ClapTrap B("B");
	ScavTrap C("C");
	FragTrap D("D");
	DiamondTrap E("E");



	A.attack("B");
	B.takeDamage(5);
	B.beRepaired(2);
	B.attack("A");
	A.takeDamage(5);
	A.beRepaired(10);
	B.attack("A");
	A.takeDamage(5);
	B.attack("A");
	A.takeDamage(5);
	A.beRepaired(2);
	B.attack("A");
	A.takeDamage(5);
	C.attack("B");
	B.takeDamage(20);
	C.guardGate();
	D.beRepaired(5);
	D.attack("C");
	D.highFivesGuys();
	E.attack("A");
	E.whoAmI();
}
