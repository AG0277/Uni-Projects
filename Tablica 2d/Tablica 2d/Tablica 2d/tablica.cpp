#include "tablica.h"

float tablica::srednia()
{
	return suma() / n;
}
float tablica::norma()
{
	return sqrt(suma_kwadratow());
}