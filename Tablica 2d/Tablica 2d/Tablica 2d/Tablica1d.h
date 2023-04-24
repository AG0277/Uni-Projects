#pragma once
#include "tablica.h"


class tablica1d :public tablica {

protected:
	int rozmiar;
	int NrOfEl;
	float* tab;
	void rozszerzanie();
public:
	float suma();
	float suma_kwadratow();
	tablica1d() :rozmiar(10), NrOfEl(0), tab(new float[10]) {};
	tablica1d(const tablica1d& tab1d);
	tablica1d(int rozmiar) :rozmiar(rozmiar), NrOfEl(0), tab(new float[rozmiar]) {};
	~tablica1d();
	int getNrOfEl() const { return NrOfEl; }
	void dodaj(float element);
	float& operator[] (int i);
	friend std::ostream& operator<< (std::ostream& out, const tablica1d& tab1d);
	void operator =(const tablica1d& tablica);

};