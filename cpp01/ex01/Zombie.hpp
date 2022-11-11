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
		void set_name(std::string name);
		std::string get_name();
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif
