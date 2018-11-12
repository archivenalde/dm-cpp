#include <iostream>
#include "AvionElectrique.h"

AvionElectrique::AvionElectrique()
: Moyen(100, 250, 6)
{
    std::cout << "Avion électrique créé" << std::endl;
}

AvionElectrique::~AvionElectrique()
{}
