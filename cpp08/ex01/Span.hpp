#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
			std::vector<int> vec;
			unsigned int size;
	public:
			Span();
			Span(unsigned int n);
			Span(const Span &s);
			Span &operator=(const Span &s);
			~Span();
			void addNumber(int num);
			int shortestSpan();
			int longestSpan();
};

#endif
