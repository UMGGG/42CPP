#pragma once

#include <iostream>

template <typename T>
void inc(T &target)
{
	target++;
}

template <typename T>
void inc(const T &target)
{
	std::cout << target << " is const type!" << std::endl;
}

template <typename T>
void print(T &target)
{
	std::cout << target << std::endl;
}

template <typename T>
void iter(T *array, size_t array_len, void (*func)(T &))
{
	if (array == NULL || func == NULL)
		return ;
	for(size_t i = 0 ; i < array_len ; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void iter(const T *array, const size_t array_len, void (*func)(const T &))
{
	if (array == NULL || func == NULL)
		return ;
	for(size_t i = 0 ; i < array_len ; i++)
	{
		func(array[i]);
	}
}
