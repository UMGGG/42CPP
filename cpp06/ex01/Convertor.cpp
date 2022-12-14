#include "Convertor.hpp"


Convertor::Convertor()
{

}

Convertor::Convertor(const std::string input): _input(input)
{

}

Convertor::Convertor(const Convertor &c): _input(c.getInput())
{
	*this = c;
}

Convertor &Convertor::operator=(const Convertor &c)
{
	if (this == &c)
		return (*this);
	this->_input = c.getInput();
	this->_char = c.getChar();
	this->_input = c.getInt();
	this->_double = c.getDouble();
	this->_int = c.getInt();
	return (*this);
}

Convertor::~Convertor()
{
}

// --------------getter----------------
std::string Convertor::getInput() const
{
	return (this->_input);
}

float Convertor::getFloat() const
{
	return (this->_float);
}

char Convertor::getChar() const
{
	return (this->_char);
}

double Convertor::getDouble() const
{
	return (this->_double);
}

int Convertor::getInt() const
{
	return (this->_int);
}
