#ifndef MOYEN_H
#define MOYEN_H

class Moyen
{
    const int capacite;
    const double vitesse;
    const double empreinte;

protected:
    Moyen(int, double, double);

public:
    int getCapacite() const;
    double getVitesse() const;
    double getEmpreinte() const;

    virtual ~Moyen();
};

#endif
