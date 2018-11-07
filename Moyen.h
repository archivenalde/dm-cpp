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

    friend bool operator==(const Moyen& m1, const Moyen& m2)
    {
        return m1.capacite == m2.capacite && m1.vitesse == m2.vitesse && m1.empreinte == m2.empreinte;
    }

};

#endif
