#ifndef COORDONNEES_H
#define COORDONNEES_H

class Coordonnees {
public:
    const double latitude;
    const double longitude;

    Coordonnees(double _latitude, double _longitude) : latitude(_latitude), longitude(_longitude) {}
};

inline bool operator<(const Coordonnees& c1, const Coordonnees& c2) {
    if (c1.latitude != c2.latitude) return c1.latitude < c2.latitude;
    else return c1.longitude < c2.longitude;
}

#endif
