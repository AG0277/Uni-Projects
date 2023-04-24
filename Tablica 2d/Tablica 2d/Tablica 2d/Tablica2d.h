#pragma once
#include "tablica.h"
#include "tablica1d.h"

class tablica2d :public tablica {

protected:
	int rozmiar;
	int NrOfEl;
	tablica1d* tab;
	void rozszerzanie();
public:

	tablica2d() :rozmiar(10), NrOfEl(0), tab(new tablica1d[10]) {};
	tablica2d(const tablica2d& tab2d);
	tablica2d(int rozmiar) :rozmiar(rozmiar), NrOfEl(0), tab(new tablica1d[rozmiar]) {};
	~tablica2d();
	float suma();
	float suma_kwadratow();
	tablica1d& operator[] (int i);
	void dodaj(const tablica1d& tablica1d);
	void dodaj_do_elementu(int index, float element);
	void operator =(const tablica2d& tablica2d);
	friend std::ostream& operator<< (std::ostream& out, const tablica2d& tab);


};