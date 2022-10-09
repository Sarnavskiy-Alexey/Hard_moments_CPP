/*
1.  —оздать шаблонную функцию, котора€ принимает итераторы на начало и конец последовательности
    слов, и вывод€щую в консоль список уникальных слов (если слово повтор€етс€ больше 1 раза, то
    вывести его надо один раз). ѕродемонстрировать работу функции, передав итераторы различных типов.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <set>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	int counter = 1;
	for (T el : v)
	{
		os << el << " | ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& v)
{
	int counter = 1;
	for (T el : v)
	{
		os << el << " | ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& v)
{
	int counter = 1;
	for (T el : v)
	{
		os << el << " | ";
	}
	return os;
}

template <typename It>
void my_unique(It it_begin, It it_end)
{
	std::set<std::string> mySet;
	std::copy(it_begin, it_end, std::inserter(mySet, mySet.end()));
	std::copy(mySet.begin(), mySet.end(), std::ostream_iterator<std::string>(std::cout, " | "));
	std::cout << std::endl;
}

int main_unique()
{
    std::vector<std::string> v{ "a", "b", "ab", "c", "a", "c", "d", "v", "a" };
    std::deque<std::string> d{ "a", "b", "ab", "c", "a", "c", "d", "v", "a" };
    std::list<std::string> l{ "a", "b", "ab", "c", "a", "c", "d", "v", "a" };

	std::cout << "Words in sequence before unique:\n";
    std::cout << v << std::endl;
    std::cout << d << std::endl;
    std::cout << l << std::endl << std::endl;

	std::cout << "Words in sequence after unique:\n";
	my_unique(v.begin(), v.end());
	my_unique(d.begin(), d.end());
	my_unique(l.begin(), l.end());

    return 0;
}
