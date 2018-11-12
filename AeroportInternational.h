#ifndef AEROPORT_INTERNATIONAL_H
#define AEROPORT_INTERNATIONAL_H

#include "Terminal.h"

class AeroportInternational : virtual public Terminal
{
protected:
    AeroportInternational();
public:
    AeroportInternational(std::string, double, double);
    ~AeroportInternational();
};

#endif
