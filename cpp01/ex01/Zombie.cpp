#include "Zombie.hpp"

	Zombie::Zombie()
	{

	}

	Zombie::Zombie(std::string sname)
	{
		name = sname;
	}

	void Zombie::announce(void)
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}

	std::string Zombie::get_name()
	{
		return(this->name);
	}

	void Zombie::set_name(std::string sname)
	{
		this->name = sname;
	}

	Zombie::~Zombie()
	{
		std::cout << name << " is dead..." << std::endl;
	}
