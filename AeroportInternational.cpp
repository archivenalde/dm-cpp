#include <iostream>
#include "AeroportInternational.h"

AeroportInternational::AeroportInternational()
: Terminal()
{}

AeroportInternational::AeroportInternational(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude)
{
    std::cout << "Construction de l'aeroport international de " << _nom << " terminée" << std::endl;
}

AeroportInternational::~AeroportInternational()
{}
