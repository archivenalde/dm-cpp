#ifndef COORDONNEES_H
#define COORDONNEES_H

class Coordonnees
{
    const double latitude;
    const double longitude;

public:
    Coordonnees(double, double);

    double getLatitude() const;
    double getLongitude() const;

    ~Coordonnees();
};

inline bool operator<(const Coordonnees& c1, const Coordonnees& c2)
{
  if (c1.getLatitude() != c2.getLatitude()) return c1.getLatitude() < c2.getLatitude();
  else return c1.getLongitude() < c2.getLongitude();
}

inline bool operator==(const Coordonnees& c1, const Coordonnees& c2)
{
    return c1.getLatitude() == c2.getLatitude() && c1.getLongitude() == c2.getLongitude();
}

inline bool operator!=(const Coordonnees& c1, const Coordonnees& c2)
{
    return !(c1.getLatitude() == c2.getLatitude() && c1.getLongitude() == c2.getLongitude());
}

#endif
