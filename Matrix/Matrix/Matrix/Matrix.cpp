#include "Matrix.h"


int Matrix::NoOfEl = 0;


Matrix::Matrix() {
    NoOfEl++;
    rows = 10;
    columns = 10;
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];

        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0;
        }
    }
}




ostream& operator<<(ostream& os, Matrix& mt)
{
    for (int i = 1; i <= mt.rows; i++) {
        for (int j = 1; j <= mt.columns; j++) {
            os << mt(j, i) << "  ";
        }
        os << "\n";
    };
    return os;
}

Matrix::Matrix(const Matrix& m) {
    NoOfEl++;
    rows = m.rows;
    columns = m.columns;
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this != &m) {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        rows = m.rows;
        columns = m.columns;
        matrix = new double* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[columns];
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix& m) {
    if (rows != m.rows || columns != m.columns) {
        std::cout << "Matrices must have the same size!" << std::endl;
        exit(1);
    }
    Matrix result(rows, columns);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            result(i, j) = (*this)(i, j) + m(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(Matrix& m) {
    if (rows != m.rows || columns != m.columns) {
        std::cout << "Matrices must have the same size!" << std::endl;
        exit(1);
    }
    Matrix result(rows, columns);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            result(i, j) = (*this)(i, j) - m(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix& m) {
    if (columns != m.rows) {
        std::cout << "Columns of first matrix must be equal to rows of second matrix!" << std::endl;
        exit(1);
    }
    Matrix result(rows, m.columns);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= m.columns; j++) {
            result(i, j) = 0.0;
            for (int k = 1; k <= columns; k++) {
                result(i, j) += (*this)(i, k) * m(k, j);
            }
        }
    }
    return result;
}



Matrix Matrix::operator*(double x) {
    Matrix result(rows, columns);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            result(i, j) = (*this)(i, j) * x;
        }
    }
    return result;
}
