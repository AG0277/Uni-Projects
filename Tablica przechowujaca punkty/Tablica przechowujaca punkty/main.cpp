#include "Punkt.h"
#include "Tablica.h"

int main()
{
	Punkt a(3, 4);
	Punkt b(6, 6);
	Punkt c(7, 8);
	Punkt d;

	std::cout << "Punkt a: ";
	a.WyswietlPunkt();
	std::cout << "Punkt b: ";
	b.WyswietlPunkt();
	std::cout << "Punkt c: ";
	c.WyswietlPunkt();
	std::cout << "Punkt d: ";
	d.WyswietlPunkt();

	a += b;
	std::cout << "punkty a+=b: ";
	a.WyswietlPunkt();

	b = c;
	std::cout << "punkty b=c: ";
	c.WyswietlPunkt();

	if (b == c)
		std::cout << "punkty " << b << c << "sa rowne" << std::endl;
	else
		std::cout << "punkty " << b << c << "nie sa rowne" << std::endl;

	a = b + c;
	std::cout << "operacja a = b+c ";
	a.WyswietlPunkt();

	std::cout << "-------------------------------" << std::endl;
	Tablica tab;
	tab.dodaj(a);
	tab.dodaj(b);
	tab.dodaj(c);
	tab.dodaj(d);
	Tablica tab1;
	Tablica tab2;
	for (int i = 0; i < 25; i++)
	{
		Punkt* e = new Punkt(i, i + 1);
		tab1.dodaj(*e);
		delete e;
	}
	for (int i = 25; i < 40; i++)
	{
		Punkt* e = new Punkt(i, i + 1);
		tab2.dodaj(*e);
		delete e;
	}
	std::cout << "tablica: " << tab << "\n\n" << "tablica 1: " << tab1 << "\n\n" << "tablica 2: " << tab2 << "\n\n";
	std::cout << "tab = tab1: ";
	tab1 = tab2;
	std::cout << tab << "\n\n";

	std::cout << "tab1 == tab2: ";
	if (tab1 == tab2)
		std::cout << "tablice sa rowne\n\n";
	else
		std::cout << "tablice nie sa rowne\n\n";

	std::cout << "tab1 += tab2: ";
	tab1 += tab2;
	std::cout << tab1 << "\n\n";

	std::cout << "operator []: ";
	tab[3] = tab1[0];
	std::cout << tab << "\n\n";

	return 0;
}