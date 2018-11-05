#ifndef LIGNE_H
#define LIGNE_H

class Terminal;

template<class T>
class Ligne
{
    T moyen;
    Terminal* origine;
    Terminal* destination;
    double frequence; // Nombre de passagers par jour

public:
    Ligne(Terminal*, Terminal*, double);
    ~Ligne();
};

#endif
