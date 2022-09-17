/*
3. Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4
   способа:

    ○ count_if и find
    ○ count_if и цикл for
    ○ цикл for и find
    ○ 2 цикла for
   
   Замерьте время каждого способа подсчета и сделайте выводы.
   Справка:
    ○ count_if - это алгоритмическая функция из STL, которая принимает 3 параметра:
      итератор на начало, итератор на конец и унарный предикат (функцию, принимающую один
      параметр и возвращающую тип bool).
    ○ find - это метод класса string, который возвращает позицию символа (строки),
      переданного в качестве параметра, в исходной строке. Если символ не найден, то метод
      возвращает string::npos.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

#include "DZ1_template_swap.h"
#include "DZ2_template_SortPointers.h"

#define K_FILENAME "PeaceAndWar1.txt"

std::string ReadFile()
{
    std::ifstream file;
    std::stringstream ss;
    file.open(K_FILENAME);
    if (file.is_open())
    {
        ss << file.rdbuf();
        file.close();
        return ss.str();
    }
    else
    {
        std::cout << "Error! File is not found!\n";
        return "";
    }
}

inline bool pr_with_find(const char& c)
{
    static const std::string abc = "аоеиуяыэюё";

    return abc.find(c) != std::string::npos;
}

bool pr_with_for(const char& c)
{
    static const std::string abc = "аоеиуяыэюё";

    for (const char& c_abc : abc)
    {
        if (c_abc == c)
        {
            return true;
        }
    }
    return false;
}

void FindVowels_1(const std::string& str)
{
    std::cout << "*****************************\n";
    std::cout << "Method #1: count_if & find\n";

    unsigned long long vowel_counter = 0;
    
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    vowel_counter = std::count_if(str.begin(), str.end(), pr_with_find);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Гласных в тексте: " << vowel_counter << std::endl;
    std::cout << "Потраченное время: " << (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)).count() << " ms" << std::endl;

    std::cout << "-----------------------------\n\n";
}

void FindVowels_2(const std::string& str)
{
    std::cout << "*****************************\n";
    std::cout << "Method #2: count_if & for\n";

    unsigned long long vowel_counter = 0;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    vowel_counter = std::count_if(str.begin(), str.end(), pr_with_for);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Гласных в тексте: " << vowel_counter << std::endl;
    std::cout << "Потраченное время: " << (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)).count() << " ms" << std::endl;

    std::cout << "-----------------------------\n\n";
}

void FindVowels_3(const std::string& str)
{
    std::cout << "*****************************\n";
    std::cout << "Method #3: for & find\n";

    unsigned long long vowel_counter = 0;
    const std::string abc = "аоеиуяыэюё";

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    for (const char &c : str)
    {
        vowel_counter += (abc.find(c) != std::string::npos ? 1 : 0);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Гласных в тексте: " << vowel_counter << std::endl;
    std::cout << "Потраченное время: " << (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)).count() << " ms" << std::endl;

    std::cout << "-----------------------------\n\n";
}

void FindVowels_4(const std::string& str)
{
    std::cout << "*****************************\n";
    std::cout << "Method #4: for & for\n";

    unsigned long long vowel_counter = 0;
    const std::string abc = "аоеиуяыэюё";

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    for (const char& c : str)
    {
        for (const char& c_abc : abc)
        {
            if (c_abc == c)
            {
                vowel_counter++;
                break;
            }
        }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Гласных в тексте: " << vowel_counter << std::endl;
    std::cout << "Потраченное время: " << (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)).count() << " ms" << std::endl;

    std::cout << "-----------------------------\n\n";
}

int main_task1()    //task_1
{
    int a = 5;
    int b = 10;
    int* c = &a;
    int* d = &b;


    std::cout << std::dec << "a = " << a << " ***** b = " << b << std::endl;
    std::cout << std::hex << "&a = " << &a << " ***** &b = " << &b << std::endl;
    std::cout << std::hex << "c = " << c << " ***** d = " << d << std::endl;
    Swap(c, d);
    std::cout << std::dec << "a = " << a << " ***** b = " << b << std::endl;
    std::cout << std::hex << "&a = " << &a << " ***** &b = " << &b << std::endl;
    std::cout << std::hex << "c = " << c << " ***** d = " << d << std::endl;
    

    return 0;
}

std::ostream& operator<< (std::ostream& os, std::vector<int*>& v)
{
    for (int* a : v)
    {
        os << *a << " ";
    }
    return os;
}

int main_task2()
{
    int a = 5, b = 10, c = 7, d = 3, e = 6;
    std::vector<int*> v = { &a, &b, &c, &d, &e };
    std::cout << v.size() << std::endl;

    std::cout << "Before sort: " << v << std::endl;
    SortPointers(v);
    std::cout << " After sort:" << v << std::endl;

    return 0;
}

int main_task3()    //task_3
{
    setlocale(LC_ALL, "Russian");

    std::string str = ReadFile();

    FindVowels_1(str);
    FindVowels_2(str);
    FindVowels_3(str);
    FindVowels_4(str);

    return 0;
}