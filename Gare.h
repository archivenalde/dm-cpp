#ifndef GARE_H
#define GARE_H

#include "Terminal.h"

class Gare : virtual public Terminal
{
protected:
    Gare();
public:
    Gare(std::string, double, double);
    ~Gare();
};

#endif
