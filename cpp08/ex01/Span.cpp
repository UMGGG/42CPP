#include "Span.hpp"

Span::Span() : _size(0)
{

};

Span::Span(unsigned int n) : _size(n)
{

};

Span::Span(const Span &s) : _size(s._size)
{
	*this = s;
};

Span &Span::operator=(const Span &s)
{
	if (this == &s)
		return (*this);
	this->_size = s._size;
	this->_vec.resize(s._size);
	for(int i = 0 ; i < s._vec.size() ; i++)
		this->_vec[i] = s._vec[i];
	return (*this);
};

Span::~Span()
{

};

void Span::addNumber(int num)
{
	if (this->_vec.size() < this->_size)
		this->_vec.push_back(num);
	else
		throw Span::OverSizeException();
};

void Span::addNumber(int num, int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		if (this->_vec.size() < this->_size)
			this->_vec.push_back(num + i);
		else
			throw Span::OverSizeException();
	}
};

int Span::shortestSpan()
{
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();
		// 정렬한 뒤 두개씩 비교해보고 제일 작은것 반환
};

int Span::longestSpan()
{
	int span;
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();
	span = *(std::max_element(_vec.begin(), _vec.end())) - *(std::min_element(_vec.begin(), _vec.end()));
	return (span);
};

const char* Span::OverSizeException::what(void) const throw()
{
	return ("Vector size is over");
}

const char* Span::NoSpanException::what(void) const throw()
{
	return ("No span can be found");
}
