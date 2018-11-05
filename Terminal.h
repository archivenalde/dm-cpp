#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <map>

#include "Ligne.h"
#include "Moyen.h"
#include "Coordonnees.h"

class Terminal
{
    const Coordonnees position;
    std::map<const Coordonnees, Ligne<Moyen>> liaisons;
    std::map<std::pair<const Coordonnees, const Coordonnees>, int> tps_moyen;
    std::map<const Coordonnees, int> flux;

public:
    Terminal(double, double);

    const Coordonnees& getPosition() const;
    const std::map<const Coordonnees, Ligne<Moyen>>& getLiaisons() const;
    const std::map<std::pair<const Coordonnees, const Coordonnees>, int>& getTempsMoyen() const;
    const std::map<const Coordonnees, int>& getFlux() const;

    double distance(const Coordonnees) const;
};

#endif
