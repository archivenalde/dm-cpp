#include "Voyage.h"

Voyage::Voyage(Terminal* _origine, Terminal* _destination)
: origine(_origine), destination(_destination)
{}

void Voyage::addCorrespondance(Ligne* _correspondance)
{
    correspondances.push_back(_correspondance);
}
