#include <iostream>
#include "Matrix.h"

int main() {

    int z = 2;

    Matrix matrix(z, z);
    cout << matrix(1, 1) << "\n";
    matrix(1, 1) = 5;
    cout << matrix(1, 1) << "\n";

    Matrix matrix1(z, z);

    double g = 1;
    for (int i = 1; i < z + 1; i++) {
        for (int j = 1; j < z + 1; j++) {
            matrix(i, j) = g + 23;
            g++;
        }
    }

    double h = 1;
    for (int i = 1; i < z + 1; i++) {
        for (int j = 1; j < z + 1; j++) {
            matrix1(i, j) = h + 23;
            h++;
        }
    }

    cout << matrix;
    cout << "\n\n\n\n\n\n";

    cout << matrix.Get_NoOfEl() << "\n\n\n\n\n\n";

    matrix1 += matrix;
    cout << "wynik dodawania macierzy: \n" << matrix1;
    cout << "\n\n\n\n\n\n";

    matrix1 -= matrix;
    cout << "wynik odejmowania macierzy: \n" << matrix1;
    cout << "\n\n\n\n\n\n";



    matrix1 = matrix1 * matrix;
    cout << "wynik mnozenia macierzy: \n" << matrix1;
    cout << "\n\n\n\n\n\n";

    Matrix matrix3(z, z);
    matrix3 = matrix1 * 3;
    cout << "wynik mnozenia macierzy: \n" << matrix3;
    cout << "\n\n\n\n\n\n";

    cout << matrix.Get_NoOfEl();

    return 0;
}