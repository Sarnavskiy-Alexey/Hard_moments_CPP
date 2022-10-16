/*
2.  Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое число равно
    15485863). Вычисления реализовать во вторичном потоке. В консоли отображать прогресс вычисления
    (в основном потоке).
*/

typedef unsigned long long T_UINT64;
typedef unsigned long T_UINT32;

#include <iostream>
#include <thread>
#include <future>

T_UINT32 GL_counter;

T_UINT64 FindSimple(T_UINT32 par_nb_simple)
{
    T_UINT64 loc_nb = 2;
    T_UINT64 loc_i;

    GL_counter = 2;

    switch (par_nb_simple)
    {
        case 0: return 1;
        case 1: return loc_nb;
        case 2: return loc_nb + 1;
        default:
        {
            loc_nb++;
            while (GL_counter != par_nb_simple + 1UL)
            {
                bool found_simple = true;
                for (loc_i = 3ULL; loc_i <= ceil(sqrt(static_cast<double>(loc_nb))); loc_i++)
                {
                    if (loc_nb % loc_i == 0)
                    {
                        loc_nb += 2;
                        found_simple = false;
                        break;
                    }
                }
                if (found_simple)
                {
                    if (GL_counter != par_nb_simple)
                    {
                        loc_nb += 2;
                    }
                    GL_counter++;
                }
            }
            return loc_nb;
        }
    }
}

int main_simple()
{
    using namespace std::chrono_literals;

    T_UINT32 percentage = 0UL;
    T_UINT32 nb_simple = 1000000UL;
    std::future<T_UINT64> res = std::async(FindSimple, nb_simple);
    
    std::cout << "Please, wait while the calculation is in progress.\nProgress (%): " << percentage << " ";
    while (GL_counter < nb_simple)
    {
        std::this_thread::sleep_for(1500ms);
        if ((GL_counter / (nb_simple / 100UL)) > percentage)
        {
            percentage = GL_counter / (nb_simple / 100UL);
            std::cout << percentage << " ";
        }
    }

    std::cout << "\nReady! The" << nb_simple <<"th simple number is: " << res.get();

    return 0;
}
