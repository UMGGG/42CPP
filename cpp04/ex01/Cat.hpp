#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
			Brain *cat_brain;
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
