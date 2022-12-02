#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
			Brain *brain;
	protected:
			std::string type;
	public:
			Dog();
			Dog(const Dog &dog);
			Dog(const Brain &brain);
			Dog &operator=(const Dog &dog);
			void makeSound() const;
			std::string getType() const;
			~Dog();
};

#endif
