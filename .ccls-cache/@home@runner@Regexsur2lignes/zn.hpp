#pragma once

#include <string>

#include "Parcelle.hpp"

class ZN : public Parcelle
{
public:
    /* Constructors */
    ZN(int num, string prop, Polygone<int> forme, int pConstructible = 0);
    ZN(Parcelle &other, int pConstructible = 0);

    /* Friends */
    friend ostream &operator<<(ostream &os, ZN const &obj);
};