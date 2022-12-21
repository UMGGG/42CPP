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
		Convertor Convert1(argv[1]);
		Convert1.printConvert();
	}
	catch(const std::exception& e)
	{
		std::cerr  << "error! " << e.what() << '\n';
		return (1);
	}
	return(0);
}
