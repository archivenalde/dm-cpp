#include <iostream>
#include "Gare.h"

Gare::Gare()
: Terminal()
{}

Gare::Gare(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude)
{
    std::cout << "Construction de la gare de " << _nom << " terminée" << std::endl;
}

Gare::~Gare()
{}
