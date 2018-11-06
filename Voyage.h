#ifndef VOYAGE_H
#define VOYAGE_H

#include <list>

#include "Ligne.h"
#include "Moyen.h"

class Terminal;

class Voyage
{
    Terminal* origine;
    Terminal* destination;

    std::list<Ligne<Moyen>*> lignes;

public:
    Voyage(Terminal*, Terminal*);

    void ajoutLigne(Ligne<Moyen>*);
    double tempsTrajetTotal(int);
    double empreinteTotale(int);

    ~Voyage();
};
#endif
