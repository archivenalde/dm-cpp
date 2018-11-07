#include "Ligne.h"
#include "Moyen.h"

template<class T>
Ligne<T>::Ligne(Terminal* _origine, Terminal* _destination, double _frequence)
: moyen(), origine(_origine), destination(_destination), frequence(_frequence)
{}

template<class T>
Ligne<T>::~Ligne()
{}

template<class T>
const T& Ligne<T>::getMoyen() const
{
    return moyen;
}

template<class T>
Terminal* Ligne<T>::getOrigine() const
{
    return origine;
}

template<class T>
Terminal* Ligne<T>::getDestination() const
{
    return destination;
}

template<class T>
int Ligne<T>::getFrequence() const
{
    return frequence;
}
