#ifndef AEROPORT_REGIONAL_H
#define AEROPORT_REGIONAL_H

#include "Terminal.h"

class AeroportRegional : virtual public Terminal
{
    static int NB_LIAISONS_MAX;
public:
    AeroportRegional(std::string, double, double);
    ~AeroportRegional();

    bool ajoutLiaisonPossible() const;
};

#endif
