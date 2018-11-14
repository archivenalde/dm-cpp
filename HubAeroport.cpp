#include <iostream>
#include "HubAeroport.h"

HubAeroport::HubAeroport()
: Terminal()
{}

HubAeroport::HubAeroport(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude, 0.75)
{
    std::cout << "Construction du hub aeroportuaire de " << _nom << " terminée" << std::endl;
}

HubAeroport::~HubAeroport()
{}
