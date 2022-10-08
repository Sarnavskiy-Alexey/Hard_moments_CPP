/*
2.  ������������ ������ a, ��������� �� 100 ������������ �����, �������������� ����� ��������
	����������� �������. �� ������ ����� ������� ����� �������� ������ ������ ����� ����� b,
	�������������� �������� ������, � ������� ����� �������� ������� ����� �����. ��������
	������������ ������� �����. ���������� ������, ������� �������� �������� ������ ��
	��������� � ���������� �� �������:

	����� (a_i - b_i)^2,   i=[0..N-1]

���:
N - ���������� ��������� � �������,
a - ������� ������� � �������� �������, b - ������� ������� � ������ �������
������������ ��������������� ���������������� ���������, �� ��������� �����.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	int counter = 1;
	for (T el : v)
	{
		os << el << " | ";
		if (counter++ % 10 == 0)
		{
			os << "\n";
		}
	}
	return os;
}

int main_signal()
{
	std::vector<double> v1(100);
	std::vector<int> v2(100);
	std::vector<double> v3(100);
	std::generate(v1.begin(), v1.end(), []() { static double a = 0.0; double sin_res = (sin(a) * 10.0); a += 0.1; return sin_res; });
	std::copy(v1.begin(), v1.end(), v2.begin());
	std::cout << "V1:\n" << v1 << std::endl << std::endl;
	std::cout << "V2:\n" << v2 << std::endl << std::endl;
	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](double a, int b) { return (a - double(b)) * (a - double(b)); });
	std::cout << "The error is: " << std::accumulate(v3.begin(), v3.end(), 0.0) << std::endl;

	return 0;
}
