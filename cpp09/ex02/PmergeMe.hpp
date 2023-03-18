#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <sys/time.h>

class PmergeMe
{
	public:
	PmergeMe(std::vector<int> &vec, std::list<int> &list)
	{
		timeval time_start;
		timeval time_end;
		gettimeofday(&time_start, NULL);
		_vec = vec;
		_list = list;
		PmergeMe::mergesort(_vec, 0, _vec.size() -1);
		gettimeofday(&time_end, NULL);
		std::cout << "time to process a range of "<< _vec.size() << "elements with std::[..]" << time_end.tv_usec- time_start.tv_usec << std::endl;
	}
	~PmergeMe()
	{
	}

	private:
	PmergeMe()
	{
	}
	PmergeMe(const PmergeMe &c)
	{
		*this = c;
	}
	PmergeMe &operator=(const PmergeMe &c)
	{
		if (this != &c)
		{
			this->_vec = c._vec;
			this->_list = c._list;
		}
		return (*this);
	}

	void mergesort(Container<T, allocator<T>> &storage, int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			mergesort(storage, left, mid);
			mergesort(storage, mid + 1, right);
			merge(storage, left, mid, right);
		}
	}

	template<typename T, template <typename, typename> class Container>
	void merge(Container<T, allocator<T>> &storage, int left, int mid, int right)
	{
		int i = left;
		int j = mid + 1;
		int k = 0;
		Container<T, allocator<T>> temp(righe - left + 1);
		while (i <= mid && j <= right)
		{
			if (arr[i] <= arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (i <= mid)
			temp[k++] = arr[i++];
		while (j <= right)
			temp[k++] = arr[j++];
		for(int p = 0; p < k ; p++)
			arr[left + p] = temp[p];
	}

	std::vector<int> _vec;
	std::list<int> _list;
};
#endif
