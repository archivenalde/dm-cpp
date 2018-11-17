#include "Flux.h"


Flux* Flux::instance = 0;

int Flux::flux[5][5] = {{-1, 13000, 5500, 4500, 2000},
                        {12500, -1, 18000, 10000, 4000},
                        {6000, 19000, -1, 6500, 2500},
                        {5000, 9000, 6000, -1, 11000},
                        {2500, 5000, 3000, 10000, -1}};

Flux::Flux()
{}

Flux::Flux(const Flux& t)
{}

Flux& Flux::operator=(Flux& t)
{
    return t;
}

const int Flux::getFlux(Ville_e v, Ville_e u) const
{
    return flux[v][u];
}

const int Flux::getFlux(int v, int u) const
{
    return flux[v][u];
}

const int Flux::getFlux(const Voyage& v) const
{
    return flux[v.getOrigine()->getIndice()][v.getDestination()->getIndice()];
}
