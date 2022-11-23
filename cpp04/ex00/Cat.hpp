#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	protected:
			std::string type;
	public:
			Cat();
			Cat(const Cat &cat);
			Cat &operator=(const Cat &cat);
			void makeSound() const;
			std::string getType() const;
			~Cat();
};

#endif
