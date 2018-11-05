#ifndef MOYEN_H
#define MOYEN_H

class Moyen {
    const int capacite;
    const double vitesse;
    const double empreinte;

public:
    Moyen(int, double, double);
    int getCapacite() const;
    double getVitesse() const;
    double getEmpreinte() const;

}
#endif
