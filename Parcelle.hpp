#pragma once

#include <string>
#include <vector>

#include "Polygone.hpp"

#define MAX_CONST_ZA_SIZE 200

using namespace std;

class Parcelle
{
private:
    string type;
    int numero;
    string proprietaire;
    float surface;
    Polygone<int> forme;
    int pConstructible;

public:
    /* Constructors */
    Parcelle(int num, string prop, Polygone<int> forme, int pConstructible = 0);
    Parcelle(Parcelle &parc, int pConstructible = 0);

    /* Getters */
    string getType(void) const;
    int getNumero(void) const;
    string getProprietaire(void) const;
    float getSurface(void) const;
    Polygone<int> getForme(void) const;
    int getPConstructible(void) const;

    /* Setters */
    void setType(string t);
    void setNumero(int n);
    void setProprietaire(string prop);
    void setForme(Polygone<int> _forme);
    void setPConstructible(int pConstructible);

    /* Destructor */
    virtual ~Parcelle() = default;  // virtual destructor

    /* Friends */
    friend ostream &operator<<(ostream &s, Parcelle const &p);
};

