#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
	int rand_num;

	srand(time(NULL));
	rand_num = rand() % 3;
	if (rand_num == 0)
		return (new A);
	else if (rand_num == 1)
		return (new B);
	else
		return (new C);
}
 // dynamic_cast는 상속관계에 있는 객체의 포인터나 참조형 타입을 변환할 때 사용함
void identify(Base* p) // 포인터타입의 dynamic_cast는 타입이 맞지않을경우 NULL을 반환함
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "pointed actual type = A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "pointed actual type = B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "pointed actual type = C" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

void identify(Base& p) // 참조타입의 dynamic_cast는 타입이 맞지않을경우 bad casting exception을 throw함
{

}

int main()
{

}
