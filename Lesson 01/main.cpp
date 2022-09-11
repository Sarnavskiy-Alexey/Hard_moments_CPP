/*
*  ������� ���� ����������� � ������� �� ���������. ��������� �������� ���������������
   ��������� ��� �������� ������, � ��������� ��������� �������� �� ����. ����� ����������
   ����������� ������ ��������� ������, � ����� ������� �� ����� ��� ����������� ����������.

*  �����! ����� ����������, ������� � �������� ������� ����������, ��������� �� ���� ��
   ���������� �����.
*/
/*
3. �������� ����� PhoneBook, ������� ����� � ���������� ������� ����: ������� � �����
   ��������. ����������� ����� ������ ������ ��������� �������� ���� ifstream � ����� ������,
   ���������� �� �����. � ���� ������������ ���������� ���������� ������ �� ����� �
   ���������� ����������. ����� PhoneBook ������ ��������� ������������� �������� ������,
   ��� ������ ���� ������ �� ���������� � �������.

*  � ������ PhoneBook ���������� ����� SortByName, ������� ������ ����������� ��������
   ���������� �� ������� ����� � ���������� �������. ���� ������� ����� �����������, ��
   ���������� ������ ����������� �� ������, ���� ����� ����� ���������, �� ����������
   ������������ �� ���������. ����������� ��������������� ������� sort.

*  ���������� ����� SortByPhone, ������� ������ ����������� �������� ���������� �� �������
   ���������. ����������� ��������������� ������� sort.

*  ���������� ����� GetPhoneNumber, ������� ��������� ������� ��������, � ���������� ������
   �� ������ � PhoneNumber. ������ ������ ���� ������, ���� ������ ����� ���� ������� �
   �������� �������� � ������. ���� �� ������ �� ���� ������� � �������� ��������, �� �
   ������ ������ ���� ������ �not found�, ���� ���� ������� ������ ������ ��������, �� �
   ������ ������ ���� �found more than 1�.

*  ���������� ����� ChangePhoneNumber, ������� ��������� �������� � ����� ����� �������� �,
   ���� ������� ��������� �������� � ����������, �� ������ ��� ����� �������� �� �����,
   ����� ������ �� ������.
*/

#include "common.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

#define CMP_SORTBYNAME [](const T_phone& a, const T_phone& b) { return a.first < b.first; }
#define CMP_SORTBYPHONE [](const T_phone& a, const T_phone& b) { return a.second < b.second; }

class PhoneBook
{
private:
    std::vector<T_phone> v_records;
public:
    PhoneBook(std::ifstream& f);
    void SortByName();
    void SortByPhone();
    std::pair<std::string, PhoneNumber> GetPhoneNumber(const std::string& par_last_name);
    void ChangePhoneNumber(Person p, PhoneNumber pn);

    // get-������� �������
    std::vector<T_phone> get_vector() const
    {
        return v_records;
    };
};

// ����������� PhoneBook � ������� ������ �� �����
PhoneBook::PhoneBook(std::ifstream& f)
{
    if (f.is_open())
    {
        while (!f.eof())
        {
            // ��������� ������ �� �����
            std::string str;
            std::getline(f, str);

            // �������������� ��� � �����
            std::string name   = str.substr(0, str.find('+') - 1);
            std::string number = str.substr(str.find('+'));

            // ��������� �����
            Person p;
            p.last_name = name.substr(0, name.find_first_of(' '));
            name.erase(0, name.find_first_of(' ') + 1);
            if (name.find(' ') == std::string::npos)
            {
                p.first_name = name;
                p.patronymic = std::nullopt;
            }
            else
            {
                p.first_name = name.substr(0, name.find_first_of(' '));
                p.patronymic = name.substr(name.find_first_of(' ') + 1);
            }

            // ��������� ������
            PhoneNumber pn;
            pn.country = std::stoi(number.substr(1, number.find('(') - 1));
            pn.city = std::stoi(number.substr(number.find('(') + 1, number.find(')') - number.find('(') - 1));
            if (number.find(' ') == std::string::npos)
            {
                pn.number = number.substr(number.find(')') + 1);
                pn.ext_number = std::nullopt;
            }
            else
            {
                pn.number = number.substr(number.find(')') + 1, number.find_first_of(' ') - (number.find(')') + 1));
                pn.ext_number = std::stoi(number.substr(number.find_first_of(' ') + 1));
            }

            v_records.push_back({ p, pn });
        }
    }
    else
    {
        std::cout << "File is not found!\n";
    }
}

// ������������� �������� ������
std::ostream& operator<<(std::ostream& os, const PhoneBook& pb)
{
    for (const T_phone& phone : pb.get_vector())
    {
        os << phone.first << " " << phone.second << "\n";
    }

    return os;
}

// ������� SortByName
void PhoneBook::SortByName()
{
    std::function<bool(const T_phone& a, const T_phone& b)> cmp = CMP_SORTBYNAME;
    std::sort(v_records.begin(), v_records.end(), cmp);
}

// ������� SortByPhone
void PhoneBook::SortByPhone()
{
    std::function<bool(const T_phone& a, const T_phone& b)> cmp = CMP_SORTBYPHONE;
    std::sort(v_records.begin(), v_records.end(), cmp);
}

// ������� GetPhoneNumber
std::pair<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& par_last_name)
{
    std::string answer = "";
    unsigned int counter = 0;
    PhoneNumber pn = { 0, 0, "0", 0};

    for (const T_phone& phone : v_records)
    {
        if (phone.first.last_name == par_last_name)
        {
            counter++;
            if (counter == 1)
            {
                pn = phone.second;
            }
        }
    }
    
    if (counter == 1)
    {
        return { "", pn };
    }
    else if (counter == 0)
    {
        return { "not found", pn };
    }
    else
    {
        return { "found more than 1", pn };
    }
}

// ������� ChangePhoneNumber
void PhoneBook::ChangePhoneNumber(Person p, PhoneNumber pn)
{
    for (T_phone& phone : v_records)
    {
        if (phone.first == p)
        {
            phone.second = pn;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream file("PhoneBook.txt"); // ���� � ����� PhoneBook.txt
    PhoneBook book(file);
    std::cout << book;
    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;
    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;
    std::cout << "-----GetPhoneNumber-----" << std::endl;
    // ������ �������, ������� ��������� ������� � ������� ����� �������� ��������, ���� ������ � �������
        auto print_phone_number = [&book](const std::string& surname) {
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            std::cout << get<1>(answer);
        else
            std::cout << get<0>(answer);
        std::cout << std::endl;
    };
    // ������ ������
    print_phone_number("������");
    print_phone_number("������");
    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{ "�����", "�������", "���������" },
        PhoneNumber{ 7, 123, "15344458", std::nullopt });
    book.ChangePhoneNumber(Person{ "��������", "���������", "������������" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book;

    return 0;
}
