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
const T& Ligne<T>::do_getMoyen() const
{
    return moyen;
}

template<class T>
Terminal* Ligne<T>::do_getOrigine() const
{
    return origine;
}

template<class T>
Terminal* Ligne<T>::do_getDestination() const
{
    return destination;
}

template<class T>
int Ligne<T>::do_getFrequence() const
{
    return frequence;
}
