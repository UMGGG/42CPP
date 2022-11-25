#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
			Brain *dog_brain;
	protected:
			std::string type;
	public:
			Dog();
			Dog(const Dog &dog);
			Dog &operator=(const Dog &dog);
			void makeSound() const;
			std::string getType() const;
			~Dog();
};

#endif
