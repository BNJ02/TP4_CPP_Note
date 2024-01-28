#pragma once

#include <string.h>
#include <ostream>
#include <string>
#include <vector>

#include "constructible.hpp"
#include "zn.hpp"
#include "Parcelle.hpp"

using namespace std;

class ZA : public ZN, public Constructible
{
private:
    string culture = "";

public:
    /* Constructors */
    ZA(int num, string prop, Polygone<int> forme, string culture = "", int pConstructible = 0);
    ZA(Parcelle &other, string culture = "", int pConstructible = 0);

    /* Override */
    float surfaceConstructible() const override;

    /* Setters */
    void setCulture(string culture);

    /* Getters */
    string getCulture() const;

    /* Friends */
    friend ostream &operator<<(ostream &os, ZA const &obj);
};