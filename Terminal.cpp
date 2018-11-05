#include <map>

#include "Terminal.h"

Terminal::Terminal(double _latitude, double _longitude)
: position(_latitude, _longitude)
{}


const Coordonnees& Terminal::getPosition() const
{
    return position;
}

const std::map<const Coordonnees&, Ligne<Moyen>>& Terminal::getLiaisons() const
{
    return liaisons;
}

const std::map<std::pair<const Coordonnees&, const Coordonnees&>, int>& Terminal::getTempsMoyen() const
{
    return tps_moyen;
}

const std::map<const Coordonnees&, int>& Terminal::getFlux() const
{
    return flux;
}


double Terminal::distance(const Coordonnees c) const
{
    return -1.0;
}
