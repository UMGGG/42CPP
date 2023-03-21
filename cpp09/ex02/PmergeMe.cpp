#include "PmergeMe.hpp"

int print_error(std::string str)
{
	std::cout << str << std::endl;
	return (1);
}

int string_to_int(std::string str)
{
	long num = 0;
	long sign = 1;
	size_t i = 0;

	if (str[0] == '-')
	{
		if (str.size() == 1)
			return (-1);
		sign = -1;
		i++;
	}
	for (; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			num = num * 10 + (str[i] - '0');
		}
		else
			return (-1);
	}
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		return (-1);
	return num * sign;
}

int PmergeMe::check_argv(int argc, char *argv[])
{
	int i = 1;
	std::string str;
	int num;

	if (argc == 1)
		return (print_error("invalid argv"));
	while (i != argc)
	{
		str = argv[i];
		num = string_to_int(str);
		if (num < 0)
			return (print_error("3invalid argv"));
		_vec.push_back(num);
		_list.push_back(num);
		i++;
	}
	return (0);
}

void PmergeMe::print_container()
{
	std::cout << "vector: ";
	std::vector<int>::iterator vec_iter = this->_vec.begin();
	while (vec_iter != this->_vec.end())
	{
		std::cout << *vec_iter << " ";
		vec_iter++;
	}
	std::cout << std::endl;
	std::cout << "list: ";
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::merge_insertion_sort_vec(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return;
	int n = vec.size();
	int step = n / 2;
	while (step > 0)
	{
		for (int i = step; i < n; i++)
		{
			int temp = vec[i];
			int j = i - step;
			while (j >= 0 && temp < vec[j])
			{
				vec[j + step] = vec[j];
				j -= step;
			}
			vec[j + step] = temp;
		}
		step /= 2;
	}
}

std::list<int>::iterator get_it(int n, std::list<int>& lst)
{
	std::list<int>::iterator itr = lst.begin();
	std::advance(itr, n - 1);
	return itr;
}

void PmergeMe::merge_insertion_sort_list(std::list<int>& lst)
{
if (lst.size() < 2)
	return;
int n = lst.size();
int step = n / 2;
	while (step > 0)
	{
		for (int i = step; i < n; i++)
		{
			int temp = vec[i];
			int j = i - step;
			while (j >= 0 && temp < vec[j])
			{
				vec[j + step] = vec[j];
				j -= step;
			}
			vec[j + step] = temp;
		}
		step /= 2;
	}
}
