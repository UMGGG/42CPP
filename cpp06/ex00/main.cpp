#include "Convertor.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "arguments error!" << std::endl;
		return (0);
	}
	try
	{
		Convertor a(argv[1]);
		std::cout << a.getType() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr  << "error!" << e.what() << '\n';
	}

}
