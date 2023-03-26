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
			return (print_error("invalid argv"));
		_vec.push_back(num);
		_deque.push_back(num);
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
	std::deque<int>::iterator deque_iter = this->_deque.begin();
	while (deque_iter != this->_deque.end())
	{
		std::cout << *deque_iter << " ";
		deque_iter++;
	}
	std::cout << std::endl;
}

void merge_sort(std::vector<int>& vec, int left, int mid, int right)
{
	std::vector<int> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;
	// left~mid 와 mid~right의 값을 비교하며 임시vector에 작은 값을 순서대로 넣어줌
	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
			temp[k++] = vec[i++];
		else
			temp[k++] = vec[j++];
	}
	// left~mid 와 mid~right에 남아있는 값이 있다면 임시vector 넣어줌
	while (i <= mid)
		temp[k++] = vec[i++];
	while (j <= right)
		temp[k++] = vec[j++];
	// 임시리스트에 정렬된 값들을 원래 임시vector에 넣어줌
	for (i = left; i <= right; i++)
		vec[i] = temp[i - left];
}

void merge_sort(std::deque<int>& deque, int left, int mid, int right)
{
	std::deque<int> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;
	// left~mid 와 mid~right의 값을 비교하며 임시vector에 작은 값을 순서대로 넣어줌
	while (i <= mid && j <= right)
	{
		if (deque[i] <= deque[j])
			temp[k++] = deque[i++];
		else
			temp[k++] = deque[j++];
	}
	// left~mid 와 mid~right에 남아있는 값이 있다면 임시vector 넣어줌
	while (i <= mid)
		temp[k++] = deque[i++];
	while (j <= right)
		temp[k++] = deque[j++];
	// 임시리스트에 정렬된 값들을 원래 임시vector에 넣어줌
	for (i = left; i <= right; i++)
		deque[i] = temp[i - left];
}

void insertion_sort(std::vector<int>& vec, int left, int right)
{
	// 왼쪽에 있는 값들과 크기를 비교하며 위치를 바꿔줌
	for (int i = left + 1; i <= right; i++)
	{
		int temp = vec[i]; // 비교할 오른쪽값
		int j = i - 1; // 왼쪽값
		while (j >= left && vec[j] > temp)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
	}
}

void insertion_sort(std::deque<int>& deque, int left, int right)
{
	// 왼쪽에 있는 값들과 크기를 비교하며 위치를 바꿔줌
	for (int i = left + 1; i <= right; i++)
	{
		int temp = deque[i]; // 비교할 오른쪽값
		int j = i - 1; // 왼쪽값
		while (j >= left && deque[j] > temp)
		{
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = temp;
	}
}

void PmergeMe::merge_insertion_sort_vec(std::vector<int> &vec, int left, int right, int size)
{
	if (left >= right)
		return;
	// 비교할 크기가 size보다 작다면 삽입정렬
	if (right - left + 1 <= size)
	{
		insertion_sort(vec, left, right);
		return;
	}
	// 크기를 절반으로 나눠 재귀로 호출
	int mid = (left + right) / 2;
	merge_insertion_sort_vec(vec, left, mid, size);
	merge_insertion_sort_vec(vec, mid + 1, right, size);
	// 여태 나눠진 모든 리스트들이 size보다 작아져서 삽입정렬이 완료됬다면 합병정렬로 합쳐주기
	merge_sort(vec, left, mid, right);
}

void PmergeMe::merge_insertion_sort_deque(std::deque<int> &deque, int left, int right, int size)
{
	if (left >= right)
		return;
	// 비교할 크기가 size보다 작다면 삽입정렬
	if (right - left + 1 <= size)
	{
		insertion_sort(deque, left, right);
		return;
	}
	// 크기를 절반으로 나눠 재귀로 호출
	int mid = (left + right) / 2;
	merge_insertion_sort_deque(deque, left, mid, size);
	merge_insertion_sort_deque(deque, mid + 1, right, size);
	// 여태 나눠진 모든 리스트들이 size보다 작아져서 삽입정렬이 완료됬다면 합병정렬로 합쳐주기
	merge_sort(deque, left, mid, right);
}

void PmergeMe::merge_sort_list(std::list<int>& lst) // 인덱스로 접근하지못하는 list를 사용하게된다면(merge sort)
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
	merge_sort_list(left);
	merge_sort_list(right);
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
	double deque_time;
	double vec_time;
	clock_t start;

	std::cout << "Before: ";
	PmergeMe::print_container();
	start = clock();
	PmergeMe::merge_insertion_sort_vec(_vec, 0, _vec.size() - 1, 3);
	vec_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	//PmergeMe::merge_sort_list(_list);
	PmergeMe::merge_insertion_sort_deque(_deque, 0, _deque.size() - 1, 3);
	deque_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	PmergeMe::print_container();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vec_time << " s" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << deque_time << " s" << std::endl;
}
