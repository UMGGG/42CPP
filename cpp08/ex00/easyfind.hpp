#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include	<iostream>
#include	<vector>
#include	<list>
#include	<deque>
#include	<stack>

class	InvalidValueException : public std::exception
{
	public:
		const char	*what() const throw()
		{
			return("Can't find value");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw InvalidValueException();
	else
		return (iter);
}

#endif
