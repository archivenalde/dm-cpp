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

const std::list<Ligne<Moyen>*>& Terminal::getLiaisons() const
{
    return liaisons;
}

const std::map<std::pair<const Coordonnees, const Coordonnees>, int>& Terminal::getTempsMoyen() const
{
    return tempsMoyen;
}

int Terminal::getTempsMoyen(const Coordonnees& c1, const Coordonnees& c2) const
{
    std::pair<const Coordonnees, const Coordonnees> coordPair = std::make_pair(c1, c2);
    //return tempsMoyen[coordPair];
    return 1;
}

const std::map<const Coordonnees, int>& Terminal::getFlux() const
{
    return flux;
}

void Terminal::ajoutLiaison(Ligne<Moyen>* l)
{
    if (l->getDestination() == this)
        liaisons.push_back(l);
}


double Terminal::distance(const Coordonnees& pos) const
{
    double horizontale, verticale, d = 2 * M_PI * RT/360.0;

    verticale = d * (pos.getLatitude() - position.getLatitude());
    horizontale = d * (pos.getLongitude() - position.getLongitude());

    return sqrt(pow(verticale, 2) + pow(horizontale, 2));
}
