#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta[10];
	for(int i = 0 ; i < 10 ; i++)
	{
		if (i < 5)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		meta[i]->makeSound();
	}
	delete[] meta;
	return 0;
}
