#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
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
			this->_list = c._list;
			this->_vec = c._vec;
		}
		return (*this);
	}

	int check_argv(int argc, char *argv[]);
	void print_container();
	void merge_insertion_sort_vec(std::vector<int>& vec);
	void merge_insertion_sort_list(std::list<int>& lst);

	std::list<int> _list;
	std::vector<int> _vec;
	double list_time;
	double vec_time;
	clock_t start;
};

#endif
