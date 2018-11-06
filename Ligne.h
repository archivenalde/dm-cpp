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
    const Terminal& getOrigine() const;
    const Terminal& getDestination() const;
    int getFrequence() const;

    ~Ligne();
};

#endif
