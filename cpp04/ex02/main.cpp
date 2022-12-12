#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
 	const Animal* j = new Dog();
 	const Animal* i = new Cat();
	// const Animal *k = new Animal();
 	delete j;//should not create a leak
 	delete i;
	system("leaks Animal");
	return 0;
}
