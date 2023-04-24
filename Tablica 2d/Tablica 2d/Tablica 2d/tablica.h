#pragma once
#include <iostream>
#include <math.h>
#include <iomanip>

class tablica {
protected:
    int n = 0;
public:
    virtual float suma() = 0;
    virtual float suma_kwadratow() = 0;
    float srednia();
    float norma();
};