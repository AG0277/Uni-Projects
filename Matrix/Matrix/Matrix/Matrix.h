#pragma once


#include <iostream>


using namespace std;

class Matrix {
private:
    int rows;
    int columns;
    double** matrix;
    static int NoOfEl;

public:
    Matrix(int r, int c) {

        NoOfEl++;
        rows = r;
        columns = c;
        matrix = new double* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[columns];

            for (int j = 0; j < columns; j++) {
                matrix[i][j] = 0;


            }
        }
    }

    double& operator() (int i, int j) {
        return matrix[i - 1][j - 1];
    }

    friend ostream& operator<<(ostream& os, Matrix& mt);

    Matrix();

    Matrix(const Matrix& m);

    Matrix& operator=(const Matrix& m);

    Matrix operator+(Matrix& m);

    Matrix operator-(Matrix& m);

    Matrix operator*(Matrix& m);


    Matrix operator*(double x);


    Matrix& operator+=(Matrix& m) { return *this = *this + m; };

    Matrix& operator-=(Matrix& m) { return *this = *this - m; };

    Matrix& operator*=(Matrix& m) { return *this = *this * m; };

    Matrix& operator*=(double x) { return *this = *this * x; };

    int Get_rows() { return rows; };

    int Get_columns() { return columns; };

    int Get_NoOfEl() { return NoOfEl; };;

    ~Matrix() {

        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        NoOfEl--;
    }
};