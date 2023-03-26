#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <limits.h>
#include <sys/time.h>

int print_error(std::string str);
int string_to_int(std::string str);

class PmergeMe
{
	public:
	PmergeMe(int argc, char *argv[])
	{
		if (PmergeMe::check_argv(argc, argv))
			exit(1);
	}
	void do_pmerge();
	~PmergeMe()
	{
	};
	private:
	PmergeMe()
	{
	};
	PmergeMe(const PmergeMe &c)
	{
		*this = c;
	}
	PmergeMe &operator=(const PmergeMe &c)
	{
		if (this != &c)
		{
			this->_deque = c._deque;
			this->_vec = c._vec;
		}
		return (*this);
	}

	int check_argv(int argc, char *argv[]);
	void print_container();
	void merge_insertion_sort_vec(std::vector<int> &vec, int left, int right, int threshold);
	void merge_insertion_sort_deque(std::deque<int> &deque, int left, int right, int size);
	void merge_sort_list(std::list<int>& lst);

	std::deque<int> _deque; // deque는 저장공간이 떨어져있음 (연속성 x)
	std::vector<int> _vec; // vector는 저장공간이 연결되어있음 (연속성 o)
};

#endif
