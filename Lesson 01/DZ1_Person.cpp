/*
1. Создайте структуру Person с 3 полями: фамилия, имя, отчество. Поле отчество должно
   быть опционального типа, т.к. не у всех людей есть отчество. Перегрузите оператор вывода
   данных для этой структуры. Также перегрузите операторы < и == (используйте tie).
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
