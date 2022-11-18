#include "ClapTrap.hpp"

int main()
{
	ClapTrap A("A");
	ClapTrap B("B");

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
	B.attack("A");
	A.takeDamage(5);
	B.attack("A");
	A.takeDamage(5);
	B.attack("A");
	A.takeDamage(5);
	A.beRepaired(3);
	A.attack("B");
}
