#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
			std::string type;
	public:
			WrongCat();
			WrongCat(const WrongCat &wrongcat);
			WrongCat &operator=(const WrongCat &wrongcat);
			void makeSound() const;
			std::string getType() const;
			~WrongCat();
};

#endif
