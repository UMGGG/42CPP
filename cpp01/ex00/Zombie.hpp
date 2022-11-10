#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string);
		void announce(void);
		void randomChump(std::string);
		Zombie *newZombie(std::string);
		~Zombie();
};

#endif
