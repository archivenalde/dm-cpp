#ifndef LIGNE_H
#define LIGNE_H

class Terminal;

template<class T>
class Ligne
{
    T moyen;
    Terminal* origine;
    Terminal* destination;
    int frequence; // Nombre de passagers par jour

public:
    Ligne(Terminal*, Terminal*, double);

    const T& getMoyen() const;
    Terminal* getOrigine() const;
    Terminal* getDestination() const;
    int getFrequence() const;

    ~Ligne();

    friend bool operator==(const Ligne<T>& l1, const Ligne<T>& l2)
    {
        return l1.getMoyen() == l2.getMoyen() && l1.getOrigine() == l2.getOrigine() && l1.getDestination() == l2.getDestination() && l1.getFrequence() == l2.getFrequence();
    }
};

#include "Ligne.tpp"


#endif
