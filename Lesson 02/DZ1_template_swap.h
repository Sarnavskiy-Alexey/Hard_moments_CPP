/*
1. ���������� ��������� ������� Swap, ������� ��������� ��� ��������� � ���������� �������
   ��������, �� ������� ��������� ��� ��������� (����� ���������� ������ ���� ���������,
   ���������� ������ ���������� � ��� �� ������� ������).
*/

#pragma once

#include <iostream>

template <typename T>
void Swap(T*& par_a, T*& par_b)
{
    T* tmp = par_a;
    par_a = par_b;
    par_b = tmp;
}
