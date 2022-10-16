/*
1.  Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout. Необходимо, чтобы
    несколько потоков могли обращаться к pcout и информация выводилась в консоль. Продемонстрируйте
    работу pcout.
*/

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>

class Pcout
{
private:
    std::mutex m;

    class pcout_in {
    private:
        std::lock_guard<std::mutex> lock;
    public:
        pcout_in(std::mutex& m) : lock(m) { }
        
        template<typename T>
        pcout_in& operator<<(T val)
        {
            std::cout << val;
            return *this;
        }
    };

public:
    template<typename T>
    pcout_in& operator<<(T val)
    {
        return pcout_in(m) << val;
    }
};


int main_pcout()
{
    Pcout pcout;

    std::thread t1([&]() { pcout << 1 << "2" << 3 << 4 << 5; });
    std::thread t2([&]() { pcout << 6 << 7 << "8" << 9 << 0; });

    t1.join();
    t2.join();

    return 0;
}