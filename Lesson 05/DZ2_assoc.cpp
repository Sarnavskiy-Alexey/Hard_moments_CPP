/*
2.  Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные
    пользователем из стандартного потока ввода и разбивать их на предложения. Далее программа должна
    вывести пользователю все предложения, а также количество слов в них, отсортировав предложения по
    количеству слов.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

std::ostream& operator<<(std::ostream& os, std::multimap<int, std::string> mm)
{
    os << "\nwords | sequence\n";
    for (auto el : mm)
    {
        os << el.first << " | " << el.second << "\n";
    }
    return os;
}

void assoc(std::string seq)
{
    std::multimap<int, std::string> myMap;
    int quant_words = 0;
    auto it_1 = seq.begin();
    auto it_2 = seq.begin();
    bool to_insert = false;
    for (it_2 = seq.begin(); it_2 != seq.end(); ++it_2)
    {
        switch (*it_2)
        {
        case ' ':
        {
            quant_words++;
            if (to_insert)
            {
                myMap.insert({ quant_words, seq.substr(it_1 - seq.begin(), it_2 - it_1) });
                it_1 = it_2 + 1;
                quant_words = 0;
                to_insert = false;
            }
            break;
        }
        case '.': case '!': case '?': to_insert = true; break;
        default: continue;
        }
    }
    myMap.insert({ ++quant_words, seq.substr(it_1 - seq.begin(), it_2 - it_1) });
    std::cout << myMap;
}

int main()
{
    std::string all_user_cin;
    std::getline(std::cin, all_user_cin);
    assoc(all_user_cin);


    return 0;
}