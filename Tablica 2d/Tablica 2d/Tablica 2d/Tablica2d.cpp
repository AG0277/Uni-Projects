#include "tablica2d.h"


tablica2d::tablica2d(const tablica2d& tab2d)
{
	rozmiar = tab2d.rozmiar;
	NrOfEl = tab2d.NrOfEl;
	n += this->NrOfEl;
	tab = new tablica1d[rozmiar];
	for (int i = 0; i = NrOfEl; i++)
		tab[i] = tab2d.tab[i];
}


tablica2d::~tablica2d()
{
	delete[] tab;
}

tablica1d& tablica2d::operator[] (int i)
{
	if (i >= NrOfEl)
		return *tab;
	else return *(tab + i);
}

std::ostream& operator<< (std::ostream& out, const tablica2d& tab)
{
	for (int i = 0; i < tab.NrOfEl; i++)
		std::cout << tab.tab[i] << "\n";
	return out;
}

void tablica2d::operator =(const tablica2d& tablica)
{
	rozmiar = tablica.rozmiar;
	NrOfEl = tablica.NrOfEl;
	delete[] tab;
	tab = new tablica1d[tablica.rozmiar];
	for (int i = 0; i < NrOfEl; i++)
		tab[i] = tablica.tab[i];
}
void tablica2d::dodaj(const tablica1d& tab1d)
{
	if (NrOfEl >= rozmiar)
		rozszerzanie();
	n = n + tab1d.getNrOfEl();
	tab[NrOfEl++] = tab1d;
}

void tablica2d::rozszerzanie()
{
	rozmiar *= 2;
	tablica1d* temparr = new tablica1d[this->rozmiar];
	for (int i = 0; i < NrOfEl; i++)
		temparr[i] = tab[i];
	tab = temparr;
}

float tablica2d::suma()
{
	float suma = 0;
	for (int i = 0; i < NrOfEl; i++)
		suma += tab[i].suma();
	return suma;

}

float tablica2d::suma_kwadratow()
{
	float wynik = 0;
	for (int i = 0; i < NrOfEl; i++)
		wynik += tab[i].suma_kwadratow();
	return wynik;
}

void tablica2d::dodaj_do_elementu(int index, float element)
{
	if (index > NrOfEl)
		return;
	if (NrOfEl >= rozmiar)
		rozszerzanie();
	if (index == NrOfEl)
		NrOfEl++;
	n++;
	tab[index].dodaj(element);
}