/*
2.  —оздать класс, представл€ющий матрицу. –еализовать в нем метод, вычисл€ющий
    определитель матрицы. ƒл€ реализации используйте контейнеры из STL.
*/

#include "DZ2_matrix.h"

DZ2_matrix::DZ2_matrix()
{
    this->m_matr.clear();
    this->m_rows = 0;
    this->m_cols = 0;
    this->m_determinant = 0.0;
}

DZ2_matrix::DZ2_matrix(const std::vector< std::vector<double>>& m)
{
    for (std::vector<double> item : m)
    {
        m_matr.push_back(item);
    }
    this->m_cols = m.size();
    if (this->m_cols != 0)
    {
        this->m_rows = m[0].size();
    }
    else
    {
        this->m_rows = 0;
    }
    this->m_determinant = Determinant(this->m_matr);
}

double DZ2_matrix::Determinant(T_Matrix m)
{
    double det = 0.0;

    if (m.size() == 1)
    {
        det = m[0][0];
        return det;
    }
    else if (m.size() > 1 && m.size() == m[0].size())
    {
        for (size_t j = 0; j < m.size(); j++)
        {
            T_Matrix tmp;
            tmp.resize(m.size() - 1);
            for (size_t i = 0; i < m.size() - 1; i++)
            {
                tmp[i].resize(m[i].size() - 1);
            }

            size_t row = 0;
            for (size_t i = 0; i < m.size(); i++)
            {
                if (i != 0)
                {
                    size_t column = 0;
                    for (size_t k = 0; k < m.size(); k++)
                    {
                        if (k != j)
                        {
                            tmp[row][column] = m[i][k];
                            column++;
                        }
                    }
                    row++;
                }
            }

            det += pow(-1.0, j) * m[0][j] * Determinant(tmp);
        }

        return det;
    }

    return 0.0;
}

double DZ2_matrix::det()
{
    this->m_determinant = Determinant(this->m_matr);

    return this->m_determinant;
}

size_t DZ2_matrix::getRows() const
{
    return this->m_rows;
}

size_t DZ2_matrix::getCols() const
{
    return this->m_cols;
}

DZ2_matrix::T_Matrix DZ2_matrix::getMatr() const
{
    return this->m_matr;
}

std::ostream& operator<< (std::ostream& os, const std::vector<double> Vector)
{
    for (const double& item : Vector)
    {
        os << item << " ";
    }

    return os;
}

std::ostream& operator<< (std::ostream& os, const DZ2_matrix::T_Matrix Matrix)
{
    for (const std::vector<double> row : Matrix)
    {
        os << row << "\n";
    }

    return os;
}

std::ostream& operator<< (std::ostream& os, const DZ2_matrix& Matrix)
{
    os << Matrix.getMatr();
    if (Matrix.getRows() == 0 && Matrix.getCols() == 0)
    {
        os << "Matrix is empty!";
    }

    return os;
}
