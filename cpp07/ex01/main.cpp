#include "iter.hpp"

int main()
{
	const int arr[] = {1, 2, 3, 4, 5};
	char a[] = {'a', 'b', 'c', 'd', 'e'};
	iter(arr, 5, print); // 첫 인자에서 T의 타입이 결정나기에 함수 포인터를 사용할때에 <int>처럼 타입을 명시하지않아도 됨
	iter(a, 5, print);
	iter(arr, 5, inc);
	iter(a, 5, inc);
	std::cout << "------------------------------------" << std::endl;
	iter(arr, 5, print);
	iter(a, 5, print);
}
