#ifndef LIGNE_H
#define LIGNE_H

#include "AbstractLigne.h"

class Terminal;

template<class T>
class Ligne : public AbstractLigne
{
    T moyen;
    Terminal* origine;
    Terminal* destination;
    int frequence; // Nombre de passage par jour

    const T& do_getMoyen() const;
    Terminal* do_getOrigine() const;
    Terminal* do_getDestination() const;
    int do_getFrequence() const;
    void do_setFrequence(int);

public:
    Ligne(Terminal*, Terminal*);
    ~Ligne();

};

#include "Ligne.tpp"


#endif
