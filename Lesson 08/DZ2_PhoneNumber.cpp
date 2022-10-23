/*
2. —оздайте структуру PhoneNumber с 4 пол€ми:

   Ј код страны (целое число)
   Ј код города (целое число)
   Ј номер (строка)
   Ј добавочный номер (целое число, опциональный тип)

*  ƒл€ этой структуры перегрузите оператор вывода. Ќеобходимо, чтобы номер телефона
   выводилс€ в формате: +7(911)1234567 12, где 7 Ц это номер страны, 911 Ц номер города,
   1234567 Ц номер, 12 Ц добавочный номер. ≈сли добавочного номера нет, то его выводить не
   надо. “акже перегрузите операторы < и == (используйте tie)
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
