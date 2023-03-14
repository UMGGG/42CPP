#include "BitcoinExchange.hpp"

void print_error_with_exit(std::string errmsg)
{
	std::cout << "error: " << errmsg << std::endl;
	exit(1);
}

float string_to_float(const std::string& str)
{
	float result = 0.0f;
	float sign = 1.0f;
	float fraction = 1.0f;
	size_t i = 0;

	if (str.length() == 0)
		print_error_with_exit("Empty string");
	if (str[0] == '-')
	{
		sign = -1.0f;
		i++;
	}
	bool hasFraction = false;
	for (; i < str.length(); i++)
	{
		char c = str[i];
		if (c >= '0' && c <= '9')
		{
			if (hasFraction)
			{
				fraction *= 0.1f;
				result += (c - '0') * fraction;
			}
			else
				result = result * 10.0f + (c - '0');
		}
		else if (c == '.')
		{
			if (hasFraction)
				print_error_with_exit("Invalid character");
			else
			hasFraction = true;
		}
		else
			print_error_with_exit("Invalid character");
	}
	return sign * result;
}


int check_data(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (i == 4 || i == 7)
		{
			if (str[i] != '-')
				print_error_with_exit("1bad input => " + str);
		}
		else if (i == 11)
		{
			if (str[i] != '|')
				print_error_with_exit("2bad input => " + str);
		}
		else if (i == 10 || i == 12)
		{
			if (str[i] != ' ')
				print_error_with_exit("3bad input => " + str);
		}
		else if (str[i] != '\0')
		{
			if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != '-')
				print_error_with_exit("4bad input => " + str);
		}
		i++;
	}
	if(i < 13)
		print_error_with_exit("5bad input => " + str);
	return (0);
}

float	BitcoinExchange::get_price(std::string date)
{
	float data;

	std::map<std::string, float>::iterator it;
	it = _btcdata.find(date);
	if (it != _btcdata.end())
		return (it->second);

	std::pair<std::map<std::string, float>::iterator, bool> ret;
	ret = _btcdata.insert(std::pair<std::string, float> (date, 0.0f));
	if (ret.first == _btcdata.begin())
		print_error_with_exit("btc data is not exist");
	ret.first--;
	data = ret.first->second;
	ret.first++;
	_btcdata.erase(ret.first);
	return (data);
}

void BitcoinExchange::print_map(std::string date, float num)
{
		std::cout << date << " => " << num << " = " << num * get_price(date) << std::endl;
}

void BitcoinExchange::get_user_data_from_file(char *file_name)
{
	std::ifstream user_file;
	std::string read_str;
	user_file.open(file_name);
	if (!(user_file.is_open()))
		print_error_with_exit("could not open file. file is not exist");
	std::getline(user_file, read_str);
	while (!(user_file.eof()))
	{
		std::getline(user_file, read_str);
		if (read_str.size() != 0)
		{
			check_data(read_str);
			if (string_to_float(read_str.substr(13)) < 0)
				std::cout << "error: not a positive number." << std::endl;
			else
				print_map(read_str.substr(0, 10),string_to_float(read_str.substr(13)));
		}
	}
	user_file.close();
}

void	BitcoinExchange::get_btc_data_from_file(std::map<std::string, float> &map)
{
	std::ifstream btc_file;
	std::string read_str;
	std::map<std::string, float>::iterator it;
	std::pair<std::map<std::string, float>::iterator, bool> ret;
	btc_file.open("data.csv");
	if (!(btc_file.is_open()))
		print_error_with_exit("could not open file. file is not exist");
	std::getline(btc_file, read_str);
	while (!(btc_file.eof()))
	{
		std::getline(btc_file, read_str);
		if (read_str.size() != 0)
		{
			ret = map.insert(std::pair<std::string, float> (read_str.substr(0, 10),string_to_float(read_str.substr(11))));
			if (ret.second == false)
				print_error_with_exit("date is already exist.");
		}
	}
	btc_file.close();
}
