#include "Moyen.h"


Moyen::Moyen(int _c, double _v, double _e)
: capacite(_c), vitesse(_v), empreinte(_e)
{}

int Moyen::getCapacite() const
{
    return capacite;
}

double Moyen::getVitesse() const
{
    return vitesse;
}

double Moyen::getEmpreinte() const
{
    return empreinte;
}
