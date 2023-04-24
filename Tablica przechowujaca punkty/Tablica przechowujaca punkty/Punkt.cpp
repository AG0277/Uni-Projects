#include "Punkt.h"


std::ostream& operator << (std::ostream& os, Punkt& punkt)
{
	os << "(" << punkt.x << "," << punkt.y << ")";
	return os;
}

void Punkt::operator+=(const Punkt& punkt)
{
	x += punkt.x;
	y += punkt.y;
}

void Punkt::operator=(const Punkt& punkt)
{
	x = punkt.x;
	y = punkt.y;
}

bool Punkt::operator==(const Punkt& punkt)
{
	if (x == punkt.x && y == punkt.y)
		return true;
	else
		return false;
}
bool Punkt::operator!=(const Punkt& punkt)
{
	if (x != punkt.x || y != punkt.y)
		return true;
	else
		return false;
}

Punkt Punkt::operator+(const Punkt& punkt)
{
	return Punkt(x + punkt.x, y + punkt.y);
}

void Punkt::WyswietlPunkt()
{
	std::cout << "x:" << x << " y:" << y << std::endl;
}
