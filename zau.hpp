#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "Polygone.hpp"
#include "Parcelle.hpp"
#include "constructible.hpp"

class ZAU : public Constructible, public Parcelle
{
public:
    /* Constructors */
    ZAU(int num, string prop, Polygone<int> forme, int pConstructible = 0);
    ZAU(Parcelle &other, int pConstructible = 0);

    /* Setters */
    float surfaceConstructible() const override;

    /* Friends */
    friend ostream &operator<<(ostream &os, ZAU const &obj);
};