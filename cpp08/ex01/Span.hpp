#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

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
			void addNumber(int num, int size);
			int shortestSpan();
			int longestSpan();
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
