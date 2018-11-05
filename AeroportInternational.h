#ifndef AEROPORT_INTERNATIONAL_H
#define AEROPORT_INTERNATIONAL_H

#include "Terminal.h"

class AeroportInternational : virtual public Terminal
{
protected:
    AeroportInternational();
public:
    AeroportInternational(double, double);
    ~AeroportInternational();
};

#endif
