#include <iostream>
#include <string>
#include <fstream>

int check_len(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int check_arg(int argc, char **argv)
{
	int i = 1;
	if (argc != 4)
	{
		std::cout << "arguments is not 3" << std::endl;
		return (1);
	}
	while (i != 4)
	{
		if (argv[i][0] == '\0')
		{
			std::cout << "arguments is empty" << std::endl;
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::string filename;
	std::string str;
	std::string savestr;
	std::ifstream readfile;
	std::ofstream writefile;
	std::string::size_type n;

	if (check_arg(argc, argv))
		return(1);
	filename = argv[1];
	readfile.open(filename);
	if (readfile.fail())
	{
		std::cout << "can't open file \""<< filename << "\"" << std::endl;
		return (1);
	}
	while(!readfile.eof())
	{
		std::getline(readfile, savestr);
		str = str + savestr;
		if(!readfile.eof())
			str = str + "\n";
	}
	readfile.close();
	writefile.open((filename + ".replace"));
	if (writefile.fail())
	{
		std::cout << "can't make file \""<< filename + ".replace" << "\"" << std::endl;
		return (1);
	}
	while(1)
	{
		n = str.find(argv[2]);
		if (n == std::string::npos)
			break;
		else
		{
			savestr = argv[3] + str.substr(((int)n + check_len(argv[2])) , str.length());
			str = str.substr(0, (int)n);
			str = str + savestr;
		}
	}
	writefile.write(str.c_str(), str.length());
	writefile.close();
	return (0);
}
