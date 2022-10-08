/*
1.  Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
    которая принимает вектор и новое число и вставляет новое число в определенную позицию в
	векторе, чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию
	insert_sorted, которая сможет аналогично работать с любым контейнером, содержащим
	любой тип значения.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template<class T1, typename T2>
void insert_sorted(T1& container, T2 data)
{
	for (auto it = container.begin(); it != container.end(); it = std::next(it))
	{
		if (*it >= data)
		{
			container.insert(it, data);
			return;
		}
	}
	container.insert(container.end(), data);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	for (T el : v)
	{
		os << el << " ";
	}
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& d)
{
	for (T el : d)
	{
		os << el << " ";
	}
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l)
{
	for (T el : l)
	{
		os << el << " ";
	}
	return os;
}

int main_insert()
{
	std::cout << "Insert in vector:\n";
	std::vector<int> v{ 1, 2, 3, 5 };
	std::cout << v << std::endl;
	insert_sorted(v, 0);
	std::cout << v << std::endl;
	insert_sorted(v, 4);
	std::cout << v << std::endl;
	insert_sorted(v, 6);
	std::cout << v << std::endl << std::endl;

	std::cout << "Insert in deque:\n";
	std::deque<int> d{ 1, 2, 3, 5 };
	std::cout << d << std::endl;
	insert_sorted(d, 0);
	std::cout << d << std::endl;
	insert_sorted(d, 4);
	std::cout << d << std::endl;
	insert_sorted(d, 6);
	std::cout << d << std::endl << std::endl;

	std::cout << "Insert in list:\n";
	std::list<double> l{ 1.5, 2.5, 3.5, 5.5 };
	std::cout << l << std::endl;
	insert_sorted(l, 0.5);
	std::cout << l << std::endl;
	insert_sorted(l, 4.5);
	std::cout << l << std::endl;
	insert_sorted(l, 6.5);
	std::cout << l << std::endl;

	return 0;
}
