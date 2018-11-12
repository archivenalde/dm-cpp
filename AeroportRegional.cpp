#include <iostream>
#include "AeroportRegional.h"

AeroportRegional::AeroportRegional()
: Terminal()
{}

AeroportRegional::AeroportRegional(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude)
{
    std::cout << "Construction de l'aeroport régional de " << _nom << " terminée" << std::endl;
}

AeroportRegional::~AeroportRegional()
{}
