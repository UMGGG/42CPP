#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
			std::string type;
	public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal &wronganimal);
			WrongAnimal &operator=(const WrongAnimal &wronganimal);
			void makeSound() const;
			std::string getType() const;
			~WrongAnimal();
};

#endif
