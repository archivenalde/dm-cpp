#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <list>
#include <map>

#include "Coordonnees.h"
#include "Ligne.h"
#include "Moyen.h"

#define RT 6378

class Terminal
{
    const Coordonnees position;
    std::list<Ligne<Moyen>> liaisons;
    std::map<std::pair<const Coordonnees, const Coordonnees>, int> tps_moyen;
    std::map<const Coordonnees, int> flux;

protected:
    Terminal();

public:
    Terminal(double, double);

    const Coordonnees& getPosition() const;
    const std::list<Ligne<Moyen>>& getLiaisons() const;
    const std::map<std::pair<const Coordonnees, const Coordonnees>, int>& getTempsMoyen() const;
    const std::map<const Coordonnees, int>& getFlux() const;

    double distance(const Coordonnees&) const;
};

#endif
