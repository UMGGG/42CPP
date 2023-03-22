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
	std::vector<int>::iterator vec_iter = this->_vec.begin();
	while (vec_iter != this->_vec.end())
	{
		std::cout << *vec_iter << " ";
		vec_iter++;
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

void PmergeMe::merge_insertion_sort_list(std::list<int>& lst)
{
	// 리스트의 크기가 1 이하면 정렬 완료
	if (lst.size() < 2)
		return;
	// 리스트를 두 부분 리스트로 분할
	std::list<int> left;
	std::list<int> right;
	std::list<int>::iterator it = lst.begin();
	for (std::size_t i = 0; i < lst.size() / 2; i++)
	{
		left.push_back(*it);
		it++;
	}
	for (; it != lst.end(); it++)
		right.push_back(*it);
	// 재귀적으로 왼쪽 부분 리스트와 오른쪽 부분 리스트를 정렬
	merge_insertion_sort_list(left);
	merge_insertion_sort_list(right);
	std::list<int>::iterator it_left = left.begin();
	std::list<int>::iterator it_right = right.begin();
	// 두 리스트를 반복하며 원소들을 비교하고, 작은 값을 list1에 삽입
	while (it_left != left.end() && it_right != right.end())
	{
		if (*it_right < *it_left)
		{
			left.insert(it_left, *it_right);
			++it_right;
		}
		else
			++it_left;
	}
	// 만약 list2에 아직 원소가 남아있다면, 남은 원소를 list1의 끝에 삽입
	if (it_right != right.end())
		left.splice(left.end(), right, it_right, right.end());
	// 기존 lst를 비워주고 정렬한 left를 lst에 넣어줌
	lst.clear();
	lst = left;
}

void PmergeMe::do_pmerge()
{
	std::cout << "Before: ";
	PmergeMe::print_container();
	start = clock();
	PmergeMe::merge_insertion_sort_vec(_vec);
	vec_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	PmergeMe::merge_insertion_sort_list(_list);
	list_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	PmergeMe::print_container();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vec_time << " s" << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << list_time << " s" << std::endl;
}
