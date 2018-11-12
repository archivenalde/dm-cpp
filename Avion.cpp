#include <iostream>
#include "Avion.h"

Avion::Avion()
: Moyen(150, 700, 18)
{
    std::cout << "Avion créé" << std::endl;
}

Avion::~Avion()
{}
