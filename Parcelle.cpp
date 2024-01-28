#include "Parcelle.hpp"

/*============================*/
/*         Parcelle()         */
/*============================*/
///// Constructors /////
Parcelle::Parcelle(int num, string prop, Polygone<int> forme, int pConstructible) {
  this->numero = num;
  this->proprietaire = prop;
  this->forme = forme;
}

Parcelle::Parcelle(Parcelle &parc, int pConstructible) {
  this->numero = parc.getNumero();
  this->proprietaire = parc.getProprietaire();
  this->forme = parc.getForme();
  this->surface = parc.getSurface();
}

///// Getters /////
string Parcelle::getType(void) const { return this->type; }

int Parcelle::getNumero(void) const { return this->numero; }

string Parcelle::getProprietaire(void) const { return this->proprietaire; }

float Parcelle::getSurface(void) const { return this->surface; }

Polygone<int> Parcelle::getForme(void) const { return this->forme; }

int Parcelle::getPConstructible(void) const { return this->pConstructible; }


///// Setters /////
void Parcelle::setType(string t) { this->type = t; }

void Parcelle::setNumero(int n) { this->numero = n; }

void Parcelle::setProprietaire(string prop) { this->proprietaire = prop; }

void Parcelle::setForme(Polygone<int> _forme) { this->forme = _forme; }

void Parcelle::setPConstructible(int pConstructible) { this->pConstructible = pConstructible; }

// Overload of << operator
ostream &operator<<(ostream &s, Parcelle const &p) {
  cout << "Informations de la parcelle : " << endl
       << "Type : " << p.getType() << endl
       << "Numero : " << p.getNumero() << endl
       << "Proprietaire : " << p.getProprietaire() << endl
       << "Surface : " << p.getSurface() << endl
       << "Forme : " << p.getForme() << endl;
  return s;
}
