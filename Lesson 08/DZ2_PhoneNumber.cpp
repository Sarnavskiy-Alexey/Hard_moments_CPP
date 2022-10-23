/*
2. �������� ��������� PhoneNumber � 4 ������:

   � ��� ������ (����� �����)
   � ��� ������ (����� �����)
   � ����� (������)
   � ���������� ����� (����� �����, ������������ ���)

*  ��� ���� ��������� ����������� �������� ������. ����������, ����� ����� ��������
   ��������� � �������: +7(911)1234567 12, ��� 7 � ��� ����� ������, 911 � ����� ������,
   1234567 � �����, 12 � ���������� �����. ���� ����������� ������ ���, �� ��� �������� ��
   ����. ����� ����������� ��������� < � == (����������� tie)
*/

#include "pch.h"
#include "common.h"

bool operator< (const PhoneNumber& pn1, const PhoneNumber& pn2)
{
    return tie(pn1.country, pn1.city, pn1.number, pn1.ext_number) < tie(pn2.country, pn2.city, pn2.number, pn2.ext_number);
}

bool operator== (const PhoneNumber& pn1, const PhoneNumber& pn2)
{
    return tie(pn1.country, pn1.city, pn1.number, pn1.ext_number) == tie(pn2.country, pn2.city, pn2.number, pn2.ext_number);
}

std::ostream& operator<< (std::ostream& os, const PhoneNumber& pn)
{
    os << "+" << pn.country
        << "(" << pn.city << ")"
        << pn.number;
    if (pn.ext_number.has_value())
    {
        os << " " << pn.ext_number.value();
    }
    return os;
}
