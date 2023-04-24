#pragma once
#include"Punkt.h"
class Tablica
{
	int rozmiar, ilosc_elementow;
	Punkt* tablica;

	void inicjalizacja();
	void Rozszerz();
public:
	Tablica() :rozmiar(10), ilosc_elementow(0), tablica(new Punkt[rozmiar]) {};
	template <size_t N>
	Tablica(Punkt(&tablica)[N])
	{
		rozmiar = N;
		ilosc_elementow = N;
		this->tablica = new Punkt[N];
		for (int i = 0; i < N; i++)
			this->tablica[i] = tablica[i];
	}
	~Tablica() { delete[] this->tablica; };
	Tablica(const Tablica& obiekt);
	friend std::ostream& operator << (std::ostream& os, Tablica& zbior);
	void dodaj(Punkt element);
	Punkt getAt(int index) { return tablica[index]; }
	int getSize() { return ilosc_elementow; }
	void operator =(const Tablica& tablica);
	bool operator ==(const Tablica& tablica);
	void operator +=(const Tablica& tablica);
	Punkt& operator[](int index);


};

