#include "BitcoinExchange.hpp"

void print_error_with_exit(std::string errmsg)
{
	std::cout << "error: " << errmsg << std::endl;
	exit(1);
}

double string_to_float(const std::string& str)
{
	double result = 0.0f;
	double sign = 1.0f;
	double fraction = 1.0f;
	size_t i = 0;

	if (str.length() == 0)
		return (-1);
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
				return (-1);
			else
			hasFraction = true;
		}
		else
			return (-1);
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
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
		}
		else if (i == 11)
		{
			if (str[i] != '|')
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
		}
		else if (i == 10 || i == 12)
		{
			if (str[i] != ' ')
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
		}
		else if (str[i] != '\0')
		{
			if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
		}
		i++;
	}
	if(i < 13)
	{
		std::cout << "error: bad input => " + str << std::endl;
		return (0);
	}
	return (1);
}

int	check_date(std::string str)
{
	int num;
	std::stringstream stream;
	stream.str(str);
	int i = 0;
	int flag = 0;
	while(stream >> num)
	{
		if (num <= 0)
			num *= -1;
		if (i == 0)
		{
			if (num <= 2008)
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
		}
		else if (i == 1)
		{
			if (num <= 0 || num >= 13)
			{
				if (num == 2)
					flag = 2;
				else if (num == 1 || num == 3 || num == 5 || num == 7 || num == 8 || num == 10 || num == 12)
					flag = 1;
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
		}
		else
		{
			if (flag == 0 && (num <= 0 || num >= 30))
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
			if (flag == 1 && (num <= 0 || num >= 31))
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
			if (flag == 2 && (num <= 0 || num >= 28))
			{
				std::cout << "error: bad input => " + str << std::endl;
				return (0);
			}
		}
		i++;
	}
	return (1);
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
	while (1)
	{
		std::getline(user_file, read_str);
		if (user_file.eof())
			break;
		if (!read_str.empty())
		{
			if (check_data(read_str))
			{
				if (string_to_float(read_str.substr(13)) < 0.0f)
					std::cout << "error: not a positive number or invalid value." << std::endl;
				else if (string_to_float(read_str.substr(13)) > 1000.0f)
					std::cout << "error: too large a number." << std::endl;
				else
				{
					if (check_date(read_str))
						print_map(read_str.substr(0, 10),string_to_float(read_str.substr(13)));
				}
			}
		}
		else
			std::cout << "error: empty line." << std::endl;
	}
	user_file.close();
}

void	BitcoinExchange::get_btc_data_from_file(std::map<std::string, float> &map)
{
	std::ifstream btc_file;
	std::string read_str;
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
