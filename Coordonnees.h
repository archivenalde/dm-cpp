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

inline bool operator<(const Coordonnees&, const Coordonnees&);

#endif
