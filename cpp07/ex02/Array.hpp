#pragma once

#include <exception>

template <typename T>
class Array
{
	private:
			T *_arr;
			size_t _size;
	public:
			Array(): _arr(NULL), _size(0)
			{
			}

			Array(unsigned int n): _arr(NULL), _size(n)
			{
				if (n != 0)
					this->_arr = new T[n];
			}

			Array(const Array &a): _arr(NULL), _size(a._size)
			{
				*this = a;
			}

			Array &operator=(const Array &a)
			{
				this->_size = a._size;
				if (this->_arr != NULL)
					delete[] this->_arr;
				if (a._size != 0)
				{
					this->_arr = new T[this->_size];
					for (unsigned int i = 0 ; i < a._size ; i++)
						this->_arr[i] = a._arr[i];
				}
				return (*this);
			}

			T &operator[](unsigned int n)
			{
				if (this->_arr == NULL || n >= this->_size)
				{
					throw Array<T>::InvalidIndexException();
				}
				else
					return (this->_arr[n]);
			}

			const T &operator[](const unsigned int n) const
			{
				if (this->_arr == NULL || n >= this->_size)
				{
					throw Array<T>::InvalidIndexException();
				}
				else
					return (this->_arr[n]);
			}

			const size_t size() const
			{
				return (this->_size);
			}

			~Array()
			{
				std::cout << "dest called" << std::endl;
				if (this->_arr != NULL)
					delete[] this->_arr;
			}

			class	InvalidIndexException : public std::exception
			{
				public:
					const char	*what() const throw()
					{
						return("Invalid index error");
					}
			};
};
