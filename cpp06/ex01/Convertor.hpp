#pragma once

#include <iostream>
#include <stdlib.h>
#include <exception>

class Convertor
{
	private:
		std::string _input;
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
		Convertor(const std::string);
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
