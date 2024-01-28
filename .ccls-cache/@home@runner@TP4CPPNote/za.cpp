#include "za.hpp"

using namespace std;

ZA::ZA(int num, string prop, Polygone<int> forme, string culture, int pConstructible) : ZN(num, prop, forme, pConstructible), Constructible()
{
    this->setType("ZA");
    this->culture = culture;
}

ZA::ZA(Parcelle &other, string culture, int pConstructible) : ZN(other, pConstructible)
{
    this->setType("ZA");
    this->culture = culture;
}

float ZA::surfaceConstructible() const
{
    float ret = (getPConstructible() * getSurface()) / 100;
    if (ret > MAX_CONST_ZA_SIZE)
    {
        return 200;
    }
    else
    {
        return ret;
    }
}

void ZA::setCulture(string culture)
{
    this->culture = culture;
}
string ZA::getCulture() const
{
    return this->culture;
}

ostream &operator<<(ostream &os, ZA const &obj)
{
    os << "Parcelle n°" << to_string(obj.getNumero()) << ":" << endl;
    os << "   Type                 : " << obj.getType() <<endl;
    os << "   Polygone             : " << obj.getForme() << endl;
    os << "   Propriétaire         : " << obj.getProprietaire() << endl;
    os << "   Surface              : " << to_string(obj.getSurface()) << endl;
    os << "   Type culture         : " << obj.getCulture() << endl;
    return os;
}