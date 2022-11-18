#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_int = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_int = num << this->fraction_bit;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_int = roundf(num * 256);
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
	{
		this->fixed_int = fix.getRawBits();
	}
	return (*this);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_int = raw;
}

int Fixed::getRawBits( void ) const
{
	return(this->fixed_int);
}

int Fixed::toInt( void ) const
{
	return (this->fixed_int >> this->fraction_bit);
}

float Fixed::toFloat( void ) const
{
	return((float)this->fixed_int / (256));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}
