#include "zu.hpp"

using namespace std;

ZU::ZU(int num, string prop, Polygone<int> forme, int pConstructible, float sConstruite) : ZAU(num, prop, forme, pConstructible)
{
    this->setType("ZU");
    setSurfaceConstruite(sConstruite);
}

ZU::ZU(Parcelle &other, int pConstructible, float sConstruite) : ZAU(other, pConstructible)
{
    this->setType("ZU");
    setSurfaceConstruite(sConstruite);
}

/* Quesstion prof... */
float ZU::surfaceConstructible() const
{
    return (((getPConstructible() * this->getSurface()) / 100) - getSurfaceConstruite());
}

void ZU::setSurfaceConstruite(float surface)
{
    this->surfaceConstruite = surface;
}

float ZU::getSurfaceConstruite() const
{
    return this->surfaceConstruite;
}

ostream &operator<<(ostream &os, ZU const &obj)
{
    os << "Parcelle n°" << to_string(obj.getNumero()) << ":" << endl;
    os << "   Type                 : ZU" << endl;
    os << "   Polygone             : " << obj.getForme() << endl;
    os << "   Propriétaire         : " << obj.getProprietaire() << endl;
    os << "   Surface              : " << to_string(obj.getSurface()) << endl;
    os << "   Surface construite   : " << to_string(obj.getSurfaceConstruite()) << "%" << endl;
    os << "   pConstructible       : " << to_string(obj.getPConstructible()) << "%" << endl;
    os << "   Surface constructible: " << to_string(obj.surfaceConstructible()) << "%" << endl;
    return os;
}