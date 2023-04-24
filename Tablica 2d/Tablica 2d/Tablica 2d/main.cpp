#include "tablica.h"
#include "tablica1d.h"
#include "tablica2d.h"


int main() {
    std::cout << "Tablica 1D\n";
    tablica1d test1;
    for (int i = 0; i < 15; i++)
        test1.dodaj(3.2 + i);
    std::cout << "elementy: " << test1 << "\n";
    std::cout << "suma elementow: " << test1.suma() << "\n";
    std::cout << "suma kwadratow elementow: " << test1.suma_kwadratow() << "\n";
    std::cout << "srednia arytmetyczna elementow: " << test1.srednia() << "\n";
    std::cout << "norma elementow: " << test1.norma() << "\n";

    std::cout << "\n\n\Tablica 2D\n";
    tablica2d test2;
    test2.dodaj(test1);
    for (int i = 1; i < 15; i++)
        test2.dodaj_do_elementu(i, 2.1 + i);
    test2.dodaj_do_elementu(5, 8);
    test2.dodaj_do_elementu(5, 8);
    test2.dodaj_do_elementu(5, 8);
    test2.dodaj(test1);

    std::cout << "elementy:\n" << test2 << "\n";
    std::cout << "suma elementow: " << test2.suma() << "\n";
    std::cout << "suma kwadratow elementow: " << test2.suma_kwadratow() << "\n";
    std::cout << "srednia arytmetyczna elementow: " << test2.srednia() << "\n";
    std::cout << "norma elementow: " << test2.norma() << "\n";



    return 0;
}