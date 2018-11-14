#ifndef HUB_AEROPORT_H
#define HUB_AEROPORT_H

#include "Terminal.h"

class HubAeroport : virtual public Terminal
{
    static int NB_LIAISONS_MAX;
public:
    HubAeroport(std::string, double, double);
    ~HubAeroport();

    bool ajoutLiaisonPossible() const;

};

#endif
