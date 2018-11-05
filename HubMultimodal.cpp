#include "HubMultimodal.h"

HubMultimodal::HubMultimodal()
: Terminal(), HubAeroport(), Gare()
{}

HubMultimodal::HubMultimodal(double _latitude, double _longitude)
: Terminal(_latitude, _longitude), HubAeroport(), Gare()
{}

HubMultimodal::~HubMultimodal()
{}
