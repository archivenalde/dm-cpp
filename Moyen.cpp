#include "Moyen.h"

Moyen::Moyen(int _capacite, double _vitesse, double _empreinte)
: capacite(_capacite), vitesse(_vitesse), empreinte(_empreinte)
{}

Moyen::~Moyen()
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
