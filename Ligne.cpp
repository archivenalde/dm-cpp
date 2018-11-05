#include "Ligne.h"

template<typename T>
Ligne<T>::Ligne(T _m, Terminal* _o, Terminal* _d, double _f)
: moyen(_m), origine(_o), destination(_d), frequence(_f)
{}
