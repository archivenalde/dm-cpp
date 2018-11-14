#ifndef VOYAGE_H
#define VOYAGE_H

#include <list>

#include "AbstractLigne.h"
#include "Moyen.h"

class Terminal;

class Voyage
{
    Terminal* origine;
    Terminal* destination;

    std::list<AbstractLigne*> lignes;

public:
    Voyage(Terminal*, Terminal*);

    void determinerCorrespondances(Terminal* terminauxAccessibles);

    void ajoutLigne(AbstractLigne*);
    double tempsTrajet();
    double empreinteTotale(int);

    ~Voyage();
};
#endif
