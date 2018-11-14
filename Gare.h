#ifndef GARE_H
#define GARE_H

#include "Terminal.h"

class Gare : public Terminal
{
    static int NB_LIAISONS_MAX;
public:
    Gare(std::string, double, double);
    ~Gare();

    bool ajoutLiaisonPossible() const;
};

#endif
