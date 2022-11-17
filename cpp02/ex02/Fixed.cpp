#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_int = 0;
}

Fixed::Fixed(const int num)
{
	this->fixed_int = num << this->fraction_bit;
}

Fixed::Fixed(const float num)
{
	this->fixed_int = roundf(num * 256);
}

Fixed::Fixed(const Fixed &fix)
{
	*this = fix;
}

Fixed& Fixed::operator=(const Fixed &fix)
{
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

bool Fixed::operator>(const Fixed &fix) const
{
	return (this->getRawBits() > fix.getRawBits());
}

bool Fixed::operator<(const Fixed &fix) const
{
	return (this->getRawBits() < fix.getRawBits());
}

bool Fixed::operator>=(const Fixed &fix) const
{
	return (this->getRawBits() >= fix.getRawBits());
}

bool Fixed::operator<=(const Fixed &fix) const
{
	return (this->getRawBits() <= fix.getRawBits());
}

bool Fixed::operator!=(const Fixed &fix) const
{
	return (this->getRawBits() != fix.getRawBits());
}

bool Fixed::operator==(const Fixed &fix) const
{
	return (this->getRawBits() == fix.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fix) const
{
	Fixed ret(this->toFloat() + fix.toFloat());
	return (ret);
}

Fixed Fixed::operator-(const Fixed &fix) const
{
	Fixed ret(this->toFloat() - fix.toFloat());
	return (ret);
}

Fixed Fixed::operator*(const Fixed &fix) const
{
	Fixed ret(this->toFloat() * fix.toFloat());
	return (ret);
}

Fixed Fixed::operator/(const Fixed &fix) const
{
	Fixed ret(this->toFloat() / fix.toFloat());
	return (ret);
}

Fixed& Fixed::operator++(void)
{
	this->fixed_int++;
	return(*this);
}

Fixed& Fixed::operator--(void)
{
	this->fixed_int--;
	return(*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed ret(*this);
	this->fixed_int++;
	return(ret);
}

const Fixed Fixed::operator--(int)
{
	const Fixed ret(*this);
	this->fixed_int--;
	return(ret);
}

Fixed::~Fixed()
{
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}
const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}
Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}
const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}
