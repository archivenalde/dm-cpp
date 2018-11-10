#include "Coordonnees.h"

Coordonnees::Coordonnees(double _latitude, double _longitude)
: latitude(_latitude), longitude(_longitude)
{}

Coordonnees::~Coordonnees()
{}

double Coordonnees::getLatitude() const
{
      return latitude;
}

double Coordonnees::getLongitude() const
{
      return longitude;
}
