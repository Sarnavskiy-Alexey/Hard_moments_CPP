#pragma once

#include <vector>
#include <iostream>


class DZ2_matrix
{
	// public type
public:
	typedef std::vector<std::vector<double>> T_Matrix;
	
	// private fields
private:
	T_Matrix m_matr;
	double m_determinant;
	size_t m_rows;
	size_t m_cols;

	// private methods
private:
	double Determinant(T_Matrix m);

	// public methods
public:
	DZ2_matrix();
	DZ2_matrix(const T_Matrix& m);

	size_t getRows() const;
	size_t getCols() const;
	T_Matrix getMatr() const;
	double det();
};

extern std::ostream& operator<< (std::ostream& os, std::vector<double> Vector);
extern std::ostream& operator<< (std::ostream& os, std::vector<std::vector<double>> Matrix);
extern std::ostream& operator<< (std::ostream& os, const DZ2_matrix& Matrix);
