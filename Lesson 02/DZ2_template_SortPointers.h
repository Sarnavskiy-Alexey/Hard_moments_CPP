/*
2. Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и
   сортирует указатели по значениям, на которые они указывают.
*/

#pragma once

#include <vector>
#include <algorithm>

template <typename T>
void SortPointers(std::vector<T*> &par_v)
{
	std::sort(par_v.begin(), par_v.end(), [](const T* a, const T* b) {return (*a < *b); });
}