#pragma once

#include <iostream>
#include <string>
#include <optional>
#include <ostream>
#include <iomanip>

// ��������� "�������"
typedef struct Person
{
    std::string last_name;				   // �������
    std::string first_name;				   // ���
    std::optional<std::string> patronymic; // �������� (�����������)

    friend bool operator< (const Person& p1, const Person& p2);
    friend bool operator== (const Person& p1, const Person& p2);
} Person;

extern std::ostream& operator<<(std::ostream& os, const Person& p);

/* ************************************************************************************ */

typedef unsigned int ui32; // ���������������� ����������� ��� (��� ���������� ������)

// ��������� "����� ��������"
typedef struct PhoneNumber
{
    ui32 country;                   // ��� ������
    ui32 city;                      // ��� ������
    std::string number;             // �����
    std::optional<ui32> ext_number; // ���������� ����� (�����������)

    friend bool operator< (const PhoneNumber& pn1, const PhoneNumber& pn2);
    friend bool operator== (const PhoneNumber& pn1, const PhoneNumber& pn2);
} PhoneNumber;

extern std::ostream& operator<< (std::ostream& os, const PhoneNumber& pn);

/* ************************************************************************************ */

typedef std::pair<Person, PhoneNumber> T_phone;