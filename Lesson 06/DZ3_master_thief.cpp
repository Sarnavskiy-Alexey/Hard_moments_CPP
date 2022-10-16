/*
3.  Промоделировать следующую ситуацию. Есть два человека (2 потока): хозяин и вор. Хозяин приносит
    домой вещи (функция добавляющая случайное число в вектор с периодичностью 1 раз в секунду). При
    этом у каждой вещи есть своя ценность. Вор забирает вещи (функция, которая находит наибольшее
    число и удаляет из вектора с периодичностью 1 раз в 0.5 секунд), каждый раз забирает вещь с
    наибольшей ценностью.
*/

#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <algorithm>

using namespace std::chrono_literals;

std::vector<int> precious;

void get_precious()
{
    std::this_thread::sleep_for(10ms);
    if (precious.empty())
    {
        do
        {
            precious.push_back(rand() % 100);
            std::this_thread::sleep_for(1000ms);
        } while (!precious.empty());
    }
}

void steal_precious()
{
    std::this_thread::sleep_for(10s);
    while (!precious.empty())
    {
        std::this_thread::sleep_for(500ms);
        auto max = std::max_element(precious.begin(), precious.end());
        precious.erase(max);
    }
}

int main_master_thief()
{
    //srand(time(0));
    std::thread t1(get_precious);
    t1.detach();

    std::thread t2(steal_precious);
    t2.detach();

    std::thread t3([]()
        {
            std::this_thread::sleep_for(20ms);
            while (precious.size() != 0)
            {
                system("cls");
                std::cout << "In master's house: ";
                for (int el : precious)
                {
                    std::cout << el << " | ";
                }
                std::cout << std::endl;
                std::this_thread::sleep_for(1s);
            }
        });
    t3.join();

    system("cls");
    std::cout << "All precious was stolen!\n";
    std::cout << "Number of things at home: " << precious.size() << std::endl;

    return 0;
}
