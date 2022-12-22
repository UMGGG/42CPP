#pragma once

#include <exception>

template <typename T>
class Array
{
	private:
			T *_arr;
			size_t _size;
	public:
			Array()
			{
				this->_arr = NULL;
				this->_size = 0;
			}

			Array(unsigned int n)
			{
				this->_arr = new T[n];
				this->_size = n;
			}

			Array(const Array &a)
			{
				this->_arr = new T[a._size];
				*this = a;
			}

			Array &operator=(const Array &a)
			{
				this->_size = a._size;
				if (this->_arr != NULL)
					delete[] this->_arr;
				if (a.size() != 0)
				{
					this->_arr = new T[this->_size];
					for (unsigned int i = 0 ; i < a._size ; i++)
						this->_arr[i] = a._arr[i];
				}
				return (*this);
			}

			~Array()
			{
				if (this->_arr != NULL)
					delete[] this->_arr;
			}
};
