#pragma once

#include <iostream>
#include <stdlib.h>
#include <exception>
#include <string>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define ERROR 4
# define NAN_INF 5

class Convertor
{
	private:
		std::string _input;
		int			_type;
		int			_int;
		float		_float;
		double		_double;
		char		_char;
		void startConvert();
		void checkInput();
		float toFloat();
		char toChar();
		double toDouble();
		int toInt();
		Convertor();
	public:
		Convertor(const std::string input);
		Convertor(const Convertor &c);
		Convertor &operator=(const Convertor &c);
		std::string getInput() const;
		float getFloat() const;
		char getChar() const;
		double getDouble() const;
		int getInt() const;
		~Convertor();
	class excep: public std::exception
	{
		public:
				const char* what( void ) const throw();
	};
};
