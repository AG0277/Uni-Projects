#include "Tablica.h"


Tablica::Tablica(const Tablica& obiekt)
{
	this->rozmiar = obiekt.rozmiar;
	this->ilosc_elementow = obiekt.ilosc_elementow;
	tablica = new Punkt[obiekt.rozmiar];
	for (int i = 0; i < ilosc_elementow; i++)
		this->tablica[i] = obiekt.tablica[i];
}

std::ostream& operator << (std::ostream& os, Tablica& tablica)
{
	for (int i = 0; i < tablica.ilosc_elementow; i++)
		os << tablica[i] << ' ';
	return os;
}

void Tablica::inicjalizacja()
{

	Punkt a(0, 0);
	for (int i = ilosc_elementow; i < rozmiar; i++)
		tablica[i] = a;
}
void Tablica::Rozszerz()
{
	rozmiar *= 2;
	Punkt* tempArr = new Punkt[rozmiar];
	for (int i = 0; i < ilosc_elementow; i++)
		tempArr[i] = tablica[i];
	delete[] tablica;
	tablica = tempArr;
	inicjalizacja();
}

void Tablica::dodaj(Punkt element)
{
	if (ilosc_elementow >= rozmiar)
		Rozszerz();
	tablica[ilosc_elementow++] = element;
}

void Tablica::operator =(const Tablica& tablica)
{
	this->rozmiar = tablica.rozmiar;
	this->ilosc_elementow = tablica.ilosc_elementow;
	delete[] this->tablica;
	this->tablica = new Punkt[rozmiar];
	for (int i = 0; i < ilosc_elementow; i++)
		this->tablica[i] = tablica.tablica[i];
}

bool Tablica::operator ==(const Tablica& tablica)
{
	if (this->rozmiar == tablica.rozmiar)
	{
		for (int i = 0; i < ilosc_elementow; i++)
		{
			if (this->tablica[i] != tablica.tablica[i])
				return false;
		}
		return true;
	}
	else
		return false;
	return true;
}

void Tablica:: operator +=(const Tablica& tablica)
{
	for (int i = 0; i < tablica.ilosc_elementow; i++)
		dodaj(tablica.tablica[i]);
}

Punkt& Tablica::operator[](int index)
{
	if (index > this->ilosc_elementow)
		return *(this->tablica);
	return *(this->tablica + index);
}