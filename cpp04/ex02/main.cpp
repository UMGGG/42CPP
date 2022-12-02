#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
 	const Animal* j = new Dog();
 	const Animal* i = new Cat();
 	delete j;//should not create a leak
 	delete i;
 	Animal	*a[4];
	for(int i=0; i<4; i++)
	{
		if (i < 2)
			a[i] = new Cat();
		else
			a[i] = new Dog();
	}
	for(int i=0; i<4; i++)
		a[i]->makeSound();
	for(int i=0; i<4; i++)
		delete a[i];

	std::cout << "------------Deep Copy Test------------" << std::endl;
	Dog *k = new Dog();
	k->getBrain()->setAllIdeas("asdasd");
	std:: cout << "k's ideas : " << k->getBrain()->getIdeas(0) << std::endl;
	Dog *q = new Dog();
	q->getBrain()->setAllIdeas("123123");
	std:: cout << "q's ideas : "  << q->getBrain()->getIdeas(0) << std::endl;
	*q = *k;
	std:: cout << "q's copied ideas : "  << q->getBrain()->getIdeas(0) << std::endl;
	k->getBrain()->setIdeas("zzz", 0);
	std:: cout << "k's ideas : "  << k->getBrain()->getIdeas(0) << std::endl;
	delete k;
	std:: cout << "q's ideas : "  << q->getBrain()->getIdeas(0) << std::endl;
	delete q;

	system("leaks Animal");
	return 0;
}
