#ifndef HUB_AEROPORT_H
#define HUB_AEROPORT_H

#include "Terminal.h"

class HubAeroport : public Terminal
{
public:
    HubAeroport(double _latitude, double _longitude);
};

#endif
