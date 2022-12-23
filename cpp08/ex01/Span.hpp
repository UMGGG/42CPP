#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Span
{
	private:
			std::vector<int> _vec;
			unsigned int _size;
	public:
			Span();
			Span(unsigned int n);
			Span(const Span &s);
			Span &operator=(const Span &s);
			~Span();
			void addNumber(int num);
			void addRandom(unsigned int range);
			unsigned int shortestSpan();
			unsigned int longestSpan();
	class	OverSizeException : public std::exception
	{
		public:
			const char	*what() const throw();
	};

	class	NoSpanException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

#endif
