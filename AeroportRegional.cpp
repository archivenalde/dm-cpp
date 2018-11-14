#include <iostream>
#include "AeroportRegional.h"

int AeroportRegional::NB_LIAISONS_MAX = 1;

AeroportRegional::AeroportRegional(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude, 0.5)
{
    std::cout << "Construction de l'aeroport régional de " << _nom << " terminée" << std::endl;
}

AeroportRegional::~AeroportRegional()
{}


bool AeroportRegional::ajoutLiaisonPossible() const
{
    return (int)liaisons.size() < AeroportRegional::NB_LIAISONS_MAX;
}
