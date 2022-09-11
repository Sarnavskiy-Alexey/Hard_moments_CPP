/*
1. �������� ��������� Person � 3 ������: �������, ���, ��������. ���� �������� ������
   ���� ������������� ����, �.�. �� � ���� ����� ���� ��������. ����������� �������� ������
   ������ ��� ���� ���������. ����� ����������� ��������� < � == (����������� tie).
*/

#include "common.h"

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    return os << std::left << std::setw(12) << p.last_name << " | "
        << std::setw(10) << p.first_name << " | "
        << std::setw(14) << p.patronymic.value_or("") << " | ";
}

bool operator< (const Person& p1, const Person& p2)
{
    return tie(p1.last_name, p1.first_name, p1.patronymic) < tie(p2.last_name, p2.first_name, p2.patronymic);
}

bool operator== (const Person& p1, const Person& p2)
{
    return tie(p1.last_name, p1.first_name, p1.patronymic) == tie(p2.last_name, p2.first_name, p2.patronymic);
}
