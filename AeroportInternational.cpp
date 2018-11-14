#include <iostream>
#include "AeroportInternational.h"

int AeroportInternational::NB_LIAISONS_MAX = 4;


AeroportInternational::AeroportInternational(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude, 0.5)
{
    std::cout << "Construction de l'aeroport international de " << _nom << " terminée" << std::endl;
}

AeroportInternational::~AeroportInternational()
{}

bool AeroportInternational::ajoutLiaisonPossible() const
{
    return (int)(int)liaisons.size() < AeroportInternational::NB_LIAISONS_MAX;
}
