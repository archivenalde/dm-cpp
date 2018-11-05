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

inline bool operator<(const Coordonnees& c1, const Coordonnees& c2)
{
    if (c1.getLatitude() != c2.getLatitude()) return c1.getLatitude() < c2.getLatitude();
    else return c1.getLongitude() < c2.getLongitude();
}
