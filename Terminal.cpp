#include <list>
#include <map>
#include <cmath>

#include "Terminal.h"

Terminal::Terminal()
: position(0.0, 0.0)
{}

Terminal::Terminal(double _latitude, double _longitude)
: position(_latitude, _longitude)
{}

Terminal::~Terminal()
{}

const Coordonnees& Terminal::getPosition() const
{
    return position;
}

const std::list<Ligne<Moyen>>& Terminal::getLiaisons() const
{
    return liaisons;
}

const std::map<std::pair<const Coordonnees, const Coordonnees>, int>& Terminal::getTempsMoyen() const
{
    return tps_moyen;
}

const std::map<const Coordonnees, int>& Terminal::getFlux() const
{
    return flux;
}


double Terminal::distance(const Coordonnees& pos) const
{
    double horizontale, verticale, d = 2 * M_PI * RT/360.0;

    verticale = d * (pos.getLatitude() - position.getLatitude());
    horizontale = d * (pos.getLongitude() - position.getLongitude());

    return sqrt(pow(verticale, 2)+pow(horizontale, 2));
}
