#include "common.h"

// 1. Добавление среднего в конец списка
int main_add_average()
{
    std::list<double> l1{ 1.0, 2.0, 4.0 };
    std::list<double> l2;
    std::list<double> l3{ 4.123678 };

    std::cout << "List before addition: " << l1 << std::endl;
    AddAverage(l1);
    std::cout << " List after addition: " << l1 << std::endl;

    std::cout << "List before addition: " << l2 << std::endl;
    AddAverage(l2);
    std::cout << " List after addition: " << l2 << std::endl;

    std::cout << "List before addition: " << l3 << std::endl;
    AddAverage(l3);
    std::cout << " List after addition: " << l3 << std::endl;

    return 0;
}

// 2. Матрица
int main_matrix()
{
    DZ2_matrix::T_Matrix my_vector{ { 1.0, 4.3 }, { 7.3, 8.7 } };
    DZ2_matrix my_matrix(my_vector);

    std::cout << my_matrix << std::endl;
    std::cout << "Determinant = " << my_matrix.det() << std::endl;

    std::cout << "\n*********************\n\n";

    DZ2_matrix my_v1;

    std::cout << my_v1 << std::endl;
    std::cout << "Determinant = " << my_v1.det() << std::endl;

    std::cout << "\n*********************\n\n";

    DZ2_matrix::T_Matrix my_vector1{ { 1.0, 4.3 }, { 7.3, 8.7 }, { 6.5, 2.8 } };
    DZ2_matrix my_matrix1(my_vector1);

    std::cout << my_matrix1 << std::endl;
    std::cout << "Determinant = " << my_matrix1.det() << std::endl;

    return 0;
}
