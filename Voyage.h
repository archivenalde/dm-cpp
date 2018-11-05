#ifndef VOYAGE_H
#define VOYAGE_H

#include <list>

class Terminal;
class Ligne;

class Voyage {
    Terminal* origine;
    Terminal* destination;
    int flux;

    std::list<Ligne*> correspondances;
public:
    Voyage(Terminal*, Terminal*);

    void addCorrespondance(Ligne*);
    double tempsTrajetTotal(int);
    double empreinteTotal(int);
};
#endif
