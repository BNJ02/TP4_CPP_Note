#include "zau.hpp"

using namespace std;

ZAU::ZAU(int num, string prop, Polygone<int> forme, int pConstructible) : Parcelle(num, prop, forme, pConstructible)
{
  this->setType("ZAU");
}

ZAU::ZAU(Parcelle &other, int pConstructible) : Parcelle(other, pConstructible)
{
  this->setType("ZAU");
}

float ZAU::surfaceConstructible() const
{
    return ((getPConstructible() / 100) * this->getSurface());
}

ostream &operator<<(ostream &os, ZAU const &obj)
{
    os << "Parcelle n°" << to_string(obj.getNumero()) << ":" << endl;
    os << "   Type                 : ZAU" << endl;
    os << "   Polygone             : " << obj.getForme() << endl;
    os << "   Propriétaire         : " << obj.getProprietaire() << endl;
    os << "   Surface              : " << to_string(obj.getSurface()) << endl;
    os << "   pConstructible       : " << to_string(obj.getPConstructible()) << "%" << endl;
    os << "   Surface constructible: " << to_string(obj.surfaceConstructible()) << endl;
    return os;
}