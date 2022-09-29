/*
1.  Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение
	которого равно среднему арифметическому всех его элементов.
*/

#include "common.h"

void AddAverage(std::list<double>& List)
{
	double average = 0.0;
	if (List.size() > 0)
	{
		for (double item : List)
		{
			average += item;
		}
		List.push_back(average / List.size());
	}
	else
	{
		List.push_back(0.0);
	}
}

std::ostream& operator<<(std::ostream& os, const std::list<double>& List)
{
	for (double item : List)
	{
		os << item << " ";
	}

	return os;
}
