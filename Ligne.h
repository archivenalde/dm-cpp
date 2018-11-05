#ifndef LIGNE_H
#define LIGNE_H

class Terminal;

template<typename T>
class Ligne
{
    T moyen;
    Terminal* origine;
    Terminal* destination;
    double frequence; // Nombre de passagers par jour

public:
    Ligne(T _m, Terminal* _o, Terminal* _d, double _f);
};

//Specialisation de la classe Ligne

/*template<>
class Ligne<Moyen>
{
    Moyen moyen;
    Terminal* origine;
    Terminal* destination;
    double frequence; // Nombre de passagers par jour

public:
    Ligne(Moyen _m, Terminal* _o, Terminal* _d, double _f);
};*/

#endif
