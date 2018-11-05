#include "Voyage.h"

Voyage::Voyage(Terminal* _o, Terminal* _d)
: origine(_o), destination(_d)
{}

void Voyage::addCorrespondance(Ligne* _corr)
{
    correspondances.push_back(_corr);
}
