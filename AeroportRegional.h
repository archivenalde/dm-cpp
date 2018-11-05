#ifndef AEROPORT_REGIONAL_H
#define AEROPORT_REGIONAL_H

#include "Terminal.h"

class AeroportRegional : virtual public Terminal
{
protected:
    AeroportRegional();
public:
    AeroportRegional(double, double);
    ~AeroportRegional();
};

#endif
