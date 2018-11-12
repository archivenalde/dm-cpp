#include "HubMultimodal.h"

HubMultimodal::HubMultimodal()
: Terminal(), HubAeroport(), Gare()
{}

HubMultimodal::HubMultimodal(std::string _nom, double _latitude, double _longitude)
: Terminal(_nom, _latitude, _longitude), HubAeroport(), Gare()
{
    std::cout << "Construction du hub multimodal de " << _nom << " terminée" << std::endl;
}

HubMultimodal::~HubMultimodal()
{}
