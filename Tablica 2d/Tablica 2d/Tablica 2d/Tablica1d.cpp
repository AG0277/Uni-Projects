#include "tablica1d.h"


tablica1d::tablica1d(const tablica1d& tab1d)
{
	rozmiar = tab1d.rozmiar;
	NrOfEl = tab1d.NrOfEl;
	n += this->NrOfEl;
	tab = new float[this->rozmiar];
	for (int i = 0; i = this->NrOfEl; i++)
		tab[i] = tab1d.tab[i];
}

tablica1d::~tablica1d()
{
	delete[] tab;
}

float& tablica1d::operator[] (int i)
{
	if (i >= NrOfEl)
		return *tab;
	return *(tab + i);
}

std::ostream& operator<< (std::ostream& out, const tablica1d& tab1d)
{
	for (int i = 0; i < tab1d.NrOfEl; i++)
		out << tab1d.tab[i] << ' ';
	return out;
}

void tablica1d::operator =(const tablica1d& tablica)
{
	rozmiar = tablica.rozmiar;
	NrOfEl = tablica.NrOfEl;
	delete[] tab;
	tab = new float[rozmiar];
	for (int i = 0; i < NrOfEl; i++)
		tab[i] = tablica.tab[i];
}
void tablica1d::dodaj(float element)
{
	if (NrOfEl >= rozmiar)
		rozszerzanie();
	n++;
	tab[NrOfEl++] = element;
}


void tablica1d::rozszerzanie()
{
	rozmiar *= 2;
	float* temparr = new float[rozmiar];
	for (int i = 0; i < NrOfEl; i++)
		temparr[i] = tab[i];
	delete[] tab;
	tab = temparr;
}

float tablica1d::suma()
{
	float suma = 0;
	for (int i = 0; i < NrOfEl; i++)
		suma += tab[i];
	return suma;
}

float tablica1d::suma_kwadratow()
{
	float wynik = 0;
	for (int i = 0; i < NrOfEl; i++)
		wynik += tab[i] * tab[i];
	return wynik;
}