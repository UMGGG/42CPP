#include "DiamondTrap.hpp"

int main()
{
		DiamondTrap a;
		DiamondTrap b("DDIA");
		DiamondTrap c(a);
		a.whoAmI();
		a.attack("DDIA");
		b.whoAmI();
		b.attack("DDIA_clone");
		c.whoAmI();
}
