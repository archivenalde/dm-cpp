#include <iostream>
#include "Gare.h"

Gare::Gare(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude, 0.25)
{
    std::cout << "Construction de la gare de " << _nom << " terminée" << std::endl;
}

Gare::~Gare()
{}

bool Gare::ajoutLiaisonPossible() const
{
    return true;
}
