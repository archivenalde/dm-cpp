#ifndef AEROPORT_INTERNATIONAL_H
#define AEROPORT_INTERNATIONAL_H

#include "Terminal.h"

class AeroportInternational : public Terminal
{
    static int NB_LIAISONS_MAX;
public:
    AeroportInternational(std::string, double, double);
    ~AeroportInternational();

    bool ajoutLiaisonPossible() const;
};

#endif
