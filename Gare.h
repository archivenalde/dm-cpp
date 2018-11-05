#ifndef GARE_H
#define GARE_H

#include "Terminal.h"

class Gare : virtual public Terminal
{
protected:
    Gare();
public:
    Gare(double, double);
    ~Gare();
};

#endif
