#pragma once
#include <iostream>


class Punkt {
	int x, y;
public:
	Punkt(int x, int y) :x(x), y(y) {};
	Punkt() :x(0), y(0) {};
	Punkt(const Punkt& punkt) : x(punkt.x), y(punkt.y) {};
	friend std::ostream& operator << (std::ostream& os, Punkt& punkt);
	void operator +=(const Punkt& punkt);
	void operator =(const Punkt& punkt);
	bool operator ==(const Punkt& punkt);
	bool operator !=(const Punkt& punkt);
	Punkt operator +(const Punkt& punkt);
	void WyswietlPunkt();
};