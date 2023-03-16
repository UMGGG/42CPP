#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

void	print_error_with_exit(std::string errmsg);
double	string_to_float(const std::string& str);
int		check_data(std::string str);
int		check_date(std::string str);

class BitcoinExchange
{
	public:
		BitcoinExchange(char *file_name)
		{
			get_btc_data_from_file(_btcdata);
			get_user_data_from_file(file_name);
		}
		~BitcoinExchange()
		{

		}
		void	print_map(std::string date, float num);
	private:
		BitcoinExchange()
		{
		}
		BitcoinExchange(const BitcoinExchange &c)
		{
			*this = c;
		}
		BitcoinExchange &operator=(const BitcoinExchange &c)
		{
			if (this != &c)
				this->_btcdata = c._btcdata;
			return (*this);
		}

		std::map<std::string, float>	_btcdata;

		void	get_user_data_from_file(char *file_name);
		void	get_btc_data_from_file(std::map<std::string, float> &map);
		float	get_price(std::string date);
};

#endif
