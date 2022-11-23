#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	protected:
			std::string type;
			Brain *cat_brain;
	public:
			Cat();
			Cat(const Cat &cat);
			Cat &operator=(const Cat &cat);
			void makeSound() const;
			std::string getType() const;
			~Cat();
};

#endif
