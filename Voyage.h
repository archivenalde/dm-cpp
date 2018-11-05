#ifndef VOYAGE_H
#define VOYAGE_H

#include <list>

class Voyage {
    Terminal* origine;
    Terminal* destination;
    int flux;

    std::list<Ligne*> correspondances;
public:
    int tempsTrajetTotal(int flux);
    int empreinteTotal(int flux);
};
#endif
