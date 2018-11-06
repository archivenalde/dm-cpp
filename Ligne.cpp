#include "Ligne.h"
#include "Moyen.h"

template<class T>
Ligne<T>::Ligne(Terminal* _origine, Terminal* _destination, double _frequence)
: moyen(), origine(_origine), destination(_destination), frequence(_frequence)
{}

template<class T>
Ligne<T>::~Ligne()
{}

template<>
Ligne<Moyen>::~Ligne()
{}

template<>
const Moyen& Ligne<Moyen>::getMoyen() const
{
    return moyen;
}

template<>
const Terminal& Ligne<Moyen>::getOrigine() const
{
    return *origine;
}

template<>
const Terminal& Ligne<Moyen>::getDestination() const
{
    return *destination;
}

template<class T>
int Ligne<T>::getFrequence() const
{
    return frequence;
}
