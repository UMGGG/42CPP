#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	std::string filename;
	std::string str;
	std::ifstream readfile;
	char c;
	if (argc != 4)
	{
		std::cout << "arguments is not 3" << std::endl;
		return (1);
	}
	filename = argv[1];
	readfile.open(filename);
	if (readfile.fail())
	{
		std::cout << "can't open file \""<< filename << "\"" << std::endl;
		return (1);
	}
	while(!readfile.eof())
	{
		readfile.get(c);
		str = str + c;
	}
	readfile.close();
	return (0);
}
