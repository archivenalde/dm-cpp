#include "Moyen.h"
#include "Ligne.h"

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
