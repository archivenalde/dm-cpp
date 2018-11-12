#ifndef HUB_AEROPORT_H
#define HUB_AEROPORT_H

#include "Terminal.h"

class HubAeroport : virtual public Terminal
{
protected:
    HubAeroport();
public:
    HubAeroport(std::string, double, double);
    ~HubAeroport();
};

#endif
