#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string name;
	int num;
}	Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
