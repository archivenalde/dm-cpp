#ifndef AEROPORT_REGIONAL_H
#define AEROPORT_REGIONAL_H

#include "Terminal.h"

class AeroportRegional : virtual public Terminal
{
protected:
    AeroportRegional();
public:
    AeroportRegional(std::string, double, double);
    ~AeroportRegional();
};

#endif
