#include "Span.hpp"

Span::Span() : _size(0)
{

}

Span::Span(unsigned int n) : _size(n)
{
	this->_vec.reserve(n);
}

Span::Span(const Span &s) : _size(s._size)
{
	*this = s;
}

Span &Span::operator=(const Span &s)
{
	if (this == &s)
		return (*this);
	this->_size = s._size;
	this->_vec = s._vec;
	this->_vec.reserve(s._size);
	return (*this);
}

Span::~Span()
{

}

void Span::addNumber(int num)
{
	if (this->_vec.size() < this->_size)
		this->_vec.push_back(num);
	else
		throw Span::OverSizeException();
}

void Span::addRandom(unsigned int range)
{
	std::srand(std::time(NULL));
	for(unsigned int i = 0 ; i < range ; i++)
	{
		if (this->_vec.size() < this->_size)
			this->_vec.push_back(std::rand() % range);
		else
			throw Span::OverSizeException();
	}
}

unsigned int Span::shortestSpan()
{
	unsigned int ret = UINT_MAX;
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();
	std::sort(this->_vec.begin(), this->_vec.end());
	std::vector<int>::iterator temp = this->_vec.begin();
	std::vector<int>::iterator temp_next = this->_vec.begin() + 1;
	while (temp_next != this->_vec.end())
	{
		if ((unsigned int)(*temp_next - *temp) < ret)
			ret = *temp_next - *temp;
		++temp_next;
		++temp;
	}
	return (ret);
}

unsigned int Span::longestSpan()
{
	unsigned int span;
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();
	span = *(std::max_element(_vec.begin(), _vec.end())) - *(std::min_element(_vec.begin(), _vec.end()));
	return (span);
}

const char* Span::OverSizeException::what(void) const throw()
{
	return ("Vector size is over");
}

const char* Span::NoSpanException::what(void) const throw()
{
	return ("No span can be found");
}
